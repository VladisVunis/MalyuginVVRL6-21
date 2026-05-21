#ifndef RK_2_H
#define RK_2_H

#include "double_linked_list.h"

#include <vector>
#include <utility>
#include <string>
#include <cstdio>

class ProcessPulses : public DoubleLinkedList {
private:
    void readFile(const char* fileName);

    double normalizationCoef() const;

public:
    ProcessPulses();
    ProcessPulses(const char* fileName);
    ~ProcessPulses();

    std::vector<std::pair<double, double>> getPulse(int numNode, bool normalize = false) const;

    std::vector<std::pair<double, double>> averPulse(int startNode, int countNode) const;

    std::vector<std::pair<double, double>> diffPulse(int numNode) const;

    std::vector<std::pair<double, double>> intPulse(int numNode, int start, int end) const;

    double getRiseTime(int numNode) const;

    double getFailTime(int numNode) const;

    double getAmpl(int numNode) const;

    int getCountPulse() const;

    double getDurPulse(int numNode, int levelPercent) const;
};

enum class SaveTo {
    show = 0,
    png = 1,
    jpeg = 2
};

class Gnuplot {
private:
    FILE* pipe;
    std::string fileName;

public:
    Gnuplot();
    ~Gnuplot();

    bool isOpen() const;

    void setFileName(const std::string& name);

    void buildPulse(const std::vector<std::pair<double, double>>& pulse, SaveTo paramToSave);
};

#endif // RK_2_H
