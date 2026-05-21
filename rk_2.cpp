#include "rk_2.h"

#include <iostream>
#include <fstream>
#include <cstdint>
#include <cmath>

static int16_t makeInt16(unsigned char low, unsigned char high) {
    unsigned short value = 0;

    value = value | low;
    value = value | (high << 8);

    return (int16_t)value;
}

static double absValue(double x) {
    if (x < 0) {
        return -x;
    }

    return x;
}

static double crossingTime(double t0, double y0, double t1, double y1, double level) {
    if (y1 == y0) {
        return t0;
    }

    double k = (level - y0) / (y1 - y0);

    return t0 + k * (t1 - t0);
}

static int findPeakIndex(const std::vector<std::pair<double, double>>& pulse) {
    if (pulse.empty()) {
        return -1;
    }

    int index = 0;
    double maxValue = absValue(pulse[0].second);

    for (int i = 1; i < (int)pulse.size(); i++) {
        double value = absValue(pulse[i].second);

        if (value > maxValue) {
            maxValue = value;
            index = i;
        }
    }

    return index;
}

static double frontCrossing(const std::vector<std::pair<double, double>>& pulse, double level) {
    if (pulse.empty()) {
        return -1;
    }

    for (int i = 1; i < (int)pulse.size(); i++) {
        double y0 = absValue(pulse[i - 1].second);
        double y1 = absValue(pulse[i].second);

        if (y0 < level && y1 >= level) {
            return crossingTime(
                pulse[i - 1].first,
                y0,
                pulse[i].first,
                y1,
                level
                );
        }
    }

    return -1;
}

static double backCrossing(const std::vector<std::pair<double, double>>& pulse, double level) {
    int peakIndex = findPeakIndex(pulse);

    if (peakIndex < 0) {
        return -1;
    }

    for (int i = peakIndex + 1; i < (int)pulse.size(); i++) {
        double y0 = absValue(pulse[i - 1].second);
        double y1 = absValue(pulse[i].second);

        if (y0 >= level && y1 < level) {
            return crossingTime(
                pulse[i - 1].first,
                y0,
                pulse[i].first,
                y1,
                level
                );
        }
    }

    return -1;
}

ProcessPulses::ProcessPulses() {
}

ProcessPulses::ProcessPulses(const char* fileName) {
    readFile(fileName);
}

ProcessPulses::~ProcessPulses() {
}

void ProcessPulses::readFile(const char* fileName) {
    std::ifstream file(fileName, std::ios::binary);

    if (!file.is_open()) {
        std::cout << "error: " << fileName << std::endl;
        return;
    }

    std::vector<double> current;

    while (true) {
        unsigned char b[4];

        file.read((char*)b, 4);

        if (file.gcount() < 4) {
            break;
        }

        int16_t U = makeInt16(b[0], b[1]);
        int16_t I = makeInt16(b[2], b[3]);

        current.push_back((double)I);
    }

    if (current.empty()) {
        std::cout << "File is empty or i cant read it" << std::endl;
        return;
    }

    double maxAbs = 0;

    for (int i = 0; i < (int)current.size(); i++) {
        double v = absValue(current[i]);

        if (v > maxAbs) {
            maxAbs = v;
        }
    }

    if (maxAbs == 0) {
        std::cout << "in file tok = 0" << std::endl;
        return;
    }

    double level = maxAbs * 0.01;

    bool inPulse = false;
    Data pulse;

    for (int i = 0; i < (int)current.size(); i++) {
        double v = absValue(current[i]);

        if (!inPulse && v >= level) {
            inPulse = true;
            pulse.points.clear();
        }

        if (inPulse) {
            double t = (double)pulse.points.size();

            pulse.points.push_back(std::make_pair(t, current[i]));

            if (v < level) {
                if (pulse.points.size() > 10) {
                    push_back(&pulse);
                }

                pulse.points.clear();
                inPulse = false;
            }
        }
    }

    if (inPulse && pulse.points.size() > 10) {
        push_back(&pulse);
    }

    std::cout << "file has been read" << std::endl;
    std::cout << "impuls have found: " << getCountNodes() << std::endl;
}

std::vector<std::pair<double, double>> ProcessPulses::getPulse(int numNode, bool normalize) const {
    std::vector<std::pair<double, double>> pulse = get_Node(numNode);

    if (normalize == false) {
        return pulse;
    }

    double coef = normalizationCoef();

    for (int i = 0; i < (int)pulse.size(); i++) {
        pulse[i].second = pulse[i].second / coef;
    }

    return pulse;
}

double ProcessPulses::normalizationCoef() const {
    double maxValue = 0;

    for (int i = 0; i < getCountNodes(); i++) {
        std::vector<std::pair<double, double>> pulse = get_Node(i);

        for (int j = 0; j < (int)pulse.size(); j++) {
            double v = absValue(pulse[j].second);

            if (v > maxValue) {
                maxValue = v;
            }
        }
    }

    if (maxValue == 0) {
        return 1;
    }

    return maxValue;
}

double ProcessPulses::getAmpl(int numNode) const {
    std::vector<std::pair<double, double>> pulse = getPulse(numNode, false);

    double maxValue = 0;

    for (int i = 0; i < (int)pulse.size(); i++) {
        double v = absValue(pulse[i].second);

        if (v > maxValue) {
            maxValue = v;
        }
    }

    return maxValue;
}

int ProcessPulses::getCountPulse() const {
    return getCountNodes();
}

std::vector<std::pair<double, double>> ProcessPulses::averPulse(int startNode, int countNode) const {
    std::vector<std::pair<double, double>> result;

    if (countNode <= 0) {
        return result;
    }

    if (getCountPulse() == 0) {
        return result;
    }

    if (startNode < 0) {
        startNode = 0;
    }

    if (startNode >= getCountPulse()) {
        startNode = getCountPulse() - 1;
    }

    int realCount = countNode;

    if (startNode + realCount > getCountPulse()) {
        realCount = getCountPulse() - startNode;
    }

    int minSize = -1;

    for (int i = 0; i < realCount; i++) {
        std::vector<std::pair<double, double>> pulse = getPulse(startNode + i, false);

        if (minSize == -1 || (int)pulse.size() < minSize) {
            minSize = (int)pulse.size();
        }
    }

    if (minSize <= 0) {
        return result;
    }

    for (int i = 0; i < minSize; i++) {
        double sum = 0;
        double t = 0;

        for (int j = 0; j < realCount; j++) {
            std::vector<std::pair<double, double>> pulse = getPulse(startNode + j, false);

            t = pulse[i].first;
            sum = sum + pulse[i].second;
        }

        result.push_back(std::make_pair(t, sum / realCount));
    }

    return result;
}

std::vector<std::pair<double, double>> ProcessPulses::diffPulse(int numNode) const {
    std::vector<std::pair<double, double>> pulse = getPulse(numNode, false);
    std::vector<std::pair<double, double>> result;

    if (pulse.size() < 2) {
        return result;
    }

    for (int i = 1; i < (int)pulse.size(); i++) {
        double dt = pulse[i].first - pulse[i - 1].first;

        if (dt == 0) {
            dt = 1;
        }

        double dy = pulse[i].second - pulse[i - 1].second;

        result.push_back(std::make_pair(pulse[i].first, dy / dt));
    }

    return result;
}

std::vector<std::pair<double, double>> ProcessPulses::intPulse(int numNode, int start, int end) const {
    std::vector<std::pair<double, double>> pulse = getPulse(numNode, false);
    std::vector<std::pair<double, double>> result;

    if (pulse.size() < 2) {
        return result;
    }

    if (start < 0 || end < 0) {
        start = 0;
        end = (int)pulse.size() - 1;
    }

    if (start < 0) {
        start = 0;
    }

    if (end >= (int)pulse.size()) {
        end = (int)pulse.size() - 1;
    }

    if (start >= end) {
        return result;
    }

    double sum = 0;

    result.push_back(std::make_pair(pulse[start].first, sum));

    for (int i = start + 1; i <= end; i++) {
        double dt = pulse[i].first - pulse[i - 1].first;

        double middle = (pulse[i].second + pulse[i - 1].second) / 2.0;

        sum = sum + middle * dt;

        result.push_back(std::make_pair(pulse[i].first, sum));
    }

    return result;
}

double ProcessPulses::getRiseTime(int numNode) const {
    std::vector<std::pair<double, double>> pulse = getPulse(numNode, false);

    double ampl = getAmpl(numNode);

    if (ampl == 0) {
        return -1;
    }

    double level10 = ampl * 0.10;
    double level90 = ampl * 0.90;

    double t10 = frontCrossing(pulse, level10);
    double t90 = frontCrossing(pulse, level90);

    if (t10 < 0 || t90 < 0) {
        return -1;
    }

    return t90 - t10;
}

double ProcessPulses::getFailTime(int numNode) const {
    std::vector<std::pair<double, double>> pulse = getPulse(numNode, false);

    double ampl = getAmpl(numNode);

    if (ampl == 0) {
        return -1;
    }

    double level90 = ampl * 0.90;
    double level10 = ampl * 0.10;

    double t90 = backCrossing(pulse, level90);
    double t10 = backCrossing(pulse, level10);

    if (t10 < 0 || t90 < 0) {
        return -1;
    }

    return t10 - t90;
}

double ProcessPulses::getDurPulse(int numNode, int levelPercent) const {
    std::vector<std::pair<double, double>> pulse = getPulse(numNode, false);

    double ampl = getAmpl(numNode);

    if (ampl == 0) {
        return -1;
    }

    if (levelPercent < 0) {
        levelPercent = 50;
    }

    if (levelPercent > 100) {
        levelPercent = 100;
    }

    double level = ampl * levelPercent / 100.0;

    double t1 = frontCrossing(pulse, level);
    double t2 = backCrossing(pulse, level);

    if (t1 < 0 || t2 < 0) {
        return -1;
    }

    return t2 - t1;
}

Gnuplot::Gnuplot() {
    fileName = "pulse.png";

#ifdef _WIN32
    pipe = _popen("\"C:/Program Files/gnuplot/bin/gnuplot.exe\" -persist", "w");
#else
    pipe = popen("gnuplot -persist", "w");
#endif
}

Gnuplot::~Gnuplot() {
    if (pipe != nullptr) {
#ifdef _WIN32
        _pclose(pipe);
#else
        pclose(pipe);
#endif
    }
}

bool Gnuplot::isOpen() const {
    return pipe != nullptr;
}

void Gnuplot::setFileName(const std::string& name) {
    fileName = name;
}

void Gnuplot::buildPulse(const std::vector<std::pair<double, double>>& pulse, SaveTo paramToSave) {
    if (pipe == nullptr) {
        return;
    }

    if (pulse.empty()) {
        return;
    }

    if (paramToSave == SaveTo::png) {
        fprintf(pipe, "set terminal pngcairo size 1000,600\n");
        fprintf(pipe, "set output '%s'\n", fileName.c_str());
    } else if (paramToSave == SaveTo::jpeg) {
        fprintf(pipe, "set terminal jpeg size 1000,600\n");
        fprintf(pipe, "set output '%s'\n", fileName.c_str());
    } else {
        fprintf(pipe, "set terminal qt\n");
    }

    fprintf(pipe, "set title 'Current pulse'\n");
    fprintf(pipe, "set xlabel 't'\n");
    fprintf(pipe, "set ylabel 'I'\n");
    fprintf(pipe, "set grid\n");

    fprintf(pipe, "plot '-' with lines title 'I(t)'\n");

    for (int i = 0; i < (int)pulse.size(); i++) {
        fprintf(pipe, "%lf %lf\n", pulse[i].first, pulse[i].second);
    }

    fprintf(pipe, "e\n");

    if (paramToSave == SaveTo::png || paramToSave == SaveTo::jpeg) {
        fprintf(pipe, "set output\n");
    }

    fflush(pipe);
}



