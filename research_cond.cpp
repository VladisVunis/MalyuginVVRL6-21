#include "research_cond.h"
#include "gnuplot.h"
#include <cmath>

CircuitWork::CircuitWork(const ParamCircuit& valueElements, const ParamVoltSource& voltage) {
    schemeParam = new ParamCircuit(valueElements);
    voltageSource = new ParamVoltSource(voltage);
    stepTime = 0.01;
    curVoltageC = 0.0;
    totalTime = 8.0 * 3.14159265358979323846;
    frequency = 1.0;

    SW1 = false;
    SW2 = false;
}

CircuitWork::ParamCircuit::ParamCircuit(double C1, double R1, double R2){
    _C1 = C1;
    _R1 = R1;
    _R2 = R2;
}

CircuitWork::ParamVoltSource::ParamVoltSource(double E1,TypeSignal signal){
    _E1 = E1;
    _signalForm = signal;
}

CircuitWork::~CircuitWork(){
    delete schemeParam;
    delete voltageSource;
}

CircuitWork::CircuitWork(double C1, double R1, double R2, double E1, TypeSignal signal){
    schemeParam = new ParamCircuit(C1, R1, R2);
    voltageSource = new ParamVoltSource(E1, signal);
    stepTime = 0.01;
    curVoltageC = 0.0;
    totalTime = 8.0 * 3.14159265358979323846;
    frequency = 1.0;

    SW1 = false;
    SW2 = false;
}

double CircuitWork::getVoltageCharge(double curTime) {
    double R = schemeParam->_R1 * 1000.0;
    double C = schemeParam->_C1 * 1e-6;
    double E = voltageSource->_E1;

    return E * (1.0 - std::exp(-curTime / (R * C)));
}

double CircuitWork::getVoltageDischarge(double curTime) {
    double R = schemeParam->_R2 * 1000.0;
    double C = schemeParam->_C1 * 1e-6;
    double E = voltageSource->_E1;

    return E * std::exp(-curTime / (R * C));
}

double CircuitWork::getVoltageE1(double curTime) const{
    double E = voltageSource->_E1;
    const double PI = 3.14159265358979323846;
    double x = 2.0 * PI * frequency * curTime;

    switch (voltageSource->_signalForm) {
    case TypeSignal::constV:
        return E;

    case TypeSignal::sinus:
        return E * std::sin(x);

    case TypeSignal::meandr:
        if (std::sin(x) >= 0) {
            return E;
        } else {
            return -E;
        }

    case TypeSignal::triangle:
        return E * (2.0 / PI) * std::asin(std::sin(x));

    case TypeSignal::sawtooth:
        return E * (2.0 * (x / (2.0 * PI) - std::floor(0.5 + x / (2.0 * PI))));

    case TypeSignal::halfSinus:
        return std::max(0.0, E * std::sin(x));

    case TypeSignal::doubleHalfSinus:
        return std::abs(E * std::sin(x));

    default:
        return 0.0;
    }
}

double CircuitWork::getVoltageC(double curTime) {
    double R1 = schemeParam->_R1 * 1000.0; // кОм -> Ом
    double R2 = schemeParam->_R2 * 1000.0; // кОм -> Ом
    double C  = schemeParam->_C1 * 1e-6;   // мкФ -> Ф

    double E = getVoltageE1(curTime);

    double targetVoltage = E * R2 / (R1 + R2);

    double req = (R1 * R2) / (R1 + R2);

    double tau = req * C;

    curVoltageC = curVoltageC + (targetVoltage - curVoltageC) * (stepTime / tau);

    return curVoltageC;
}

bool CircuitWork::toggle_SW1(){
    if (SW1 == true) SW1 = false;
    else SW1 = true;
    return SW1;
}

bool CircuitWork::status_SW1() const{
    return SW1;
}

bool CircuitWork::switch_SW1(bool on){
    if(on == true){
        SW1 = true;
    }
    else{
        SW1 = false;
    }
    return SW1;
}

bool CircuitWork::toggle_SW2(){
    if (SW2 == true) SW2 = false;
    else SW2 = true;
    return SW2;
}

bool CircuitWork::status_SW2() const{
    return SW2;
}

bool CircuitWork::switch_SW2(bool on){
    if(on == true){
        SW2 = true;
    }
    else{
        SW2 = false;
    }
    return SW2;
}

void CircuitWork::getVoltage(double curTime, bool statusSW1, bool statusSW2) {
    SW1 = statusSW1;
    SW2 = statusSW2;

    double R1 = schemeParam->_R1 * 1000.0; // кОм -> Ом
    double R2 = schemeParam->_R2 * 1000.0; // кОм -> Ом
    double C  = schemeParam->_C1 * 1e-6;   // мкФ -> Ф

    double targetVoltage = 0.0;
    double tau = 0.0;

    if (SW1 == false && SW2 == false) {
        return;
    }

    if (SW1 == true && SW2 == false) {

        targetVoltage = getVoltageE1(curTime);
        tau = R1 * C;

    }
    else if (SW1 == false && SW2 == true) {

        targetVoltage = 0.0;
        tau = R2 * C;

    }
    else if(SW1 == true && SW2 == true){

        double E = getVoltageE1(curTime);

        targetVoltage = E * R2 / (R1 + R2);

        double req = (R1 * R2) / (R1 + R2);
        tau = req * C;

    }

    curVoltageC = curVoltageC + (targetVoltage - curVoltageC) * (stepTime / tau);
}

void CircuitWork::getVoltage(double curTime) {
    getVoltage(curTime, SW1, SW2);
}

double CircuitWork::getCurrentVoltageC() const {
    return curVoltageC;
}

std::vector<std::pair<double, double>> CircuitWork::getSignalVolt() const {
    std::vector<std::pair<double, double>> points;

    for (double t = 0.0; t <= totalTime; t += stepTime) {
        double voltage = getVoltageE1(t);

        points.push_back(std::pair<double, double>(t, voltage));
    }

    return points;
}

void CircuitWork::setStepTime(double step) {
    stepTime = step;
}

void CircuitWork::setFrequency(double freq) {
    frequency = freq;
}

void CircuitWork::resetVoltageC(double value) {
    curVoltageC = value;
}



