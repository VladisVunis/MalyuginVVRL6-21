#ifndef GNUPLOT_H
#define GNUPLOT_H


#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <cstdlib>

class Gnuplot {
private:
    FILE* file;

public:
    Gnuplot();
    ~Gnuplot();

    bool isOpen() const;

    void command(const std::string& cmd);

    void plotPoints(const std::vector<std::pair<double, double>>& points, const std::string& title, const std::string& xLabel = "t", const std::string& yLabel = "U, V");

    void plotTwoPoints(const std::vector<std::pair<double, double>>& points1, const std::string& title1, const std::vector<std::pair<double, double>>& points2, const std::string& title2, const std::string& xLabel = "t", const std::string& yLabel = "U, V");

    void saveJpeg(const std::string& fileName);
    void showWindow();
};

#endif // GNUPLOT_H
