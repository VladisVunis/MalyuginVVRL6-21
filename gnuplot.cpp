#include "gnuplot.h"

Gnuplot::Gnuplot() {
#ifdef _WIN32
    file = _popen(R"("C:\Program Files\gnuplot\bin\gnuplot.exe" -persistent)", "w");
#else
    file = popen("gnuplot -persistent", "w");
#endif
}

Gnuplot::~Gnuplot() {
    if (file != nullptr) {
#ifdef _WIN32
        _pclose(file);
#else
        pclose(file);
#endif
    }
}

bool Gnuplot::isOpen() const {
    return file != nullptr;
}

void Gnuplot::command(const std::string& cmd) {
    if (file == nullptr) {
        return;
    }

    fprintf(file, "%s\n", cmd.c_str());
    fflush(file);
}

void Gnuplot::showWindow() {
    command("set terminal qt");
}

void Gnuplot::saveJpeg(const std::string& fileName) {
    command("set terminal jpeg size 1200,800");
    command("set output '" + fileName + "'");
}

void Gnuplot::plotPoints(const std::vector<std::pair<double, double>>& points, const std::string& title, const std::string& xLabel, const std::string& yLabel) {
    if (file == nullptr) {
        return;
    }

    command("set grid");
    command("set xlabel '" + xLabel + "'");
    command("set ylabel '" + yLabel + "'");
    command("plot '-' with lines title '" + title + "'");

    for (const auto& point : points) {
        fprintf(file, "%lf %lf\n", point.first, point.second);
    }

    fprintf(file, "e\n");
    fflush(file);
}

void Gnuplot::plotTwoPoints(const std::vector<std::pair<double, double>>& points1, const std::string& title1, const std::vector<std::pair<double, double>>& points2, const std::string& title2, const std::string& xLabel, const std::string& yLabel) {
    if (file == nullptr) {
        return;
    }

    command("set grid");
    command("set xlabel '" + xLabel + "'");
    command("set ylabel '" + yLabel + "'");

    command("plot '-' with lines title '" + title1 + "', " "'-' with lines title '" + title2 + "'");

    for (const auto& point : points1) {
        fprintf(file, "%lf %lf\n", point.first, point.second);
    }
    fprintf(file, "e\n");

    for (const auto& point : points2) {
        fprintf(file, "%lf %lf\n", point.first, point.second);
    }
    fprintf(file, "e\n");

    fflush(file);
}
