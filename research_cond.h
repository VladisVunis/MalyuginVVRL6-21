#ifndef RESEARCH_COND_H
#define RESEARCH_COND_H

#include <vector>
#include <utility>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>

enum class TypeSignal {
    constV = 0,
    meandr = 1,
    sinus = 2,
    triangle = 3,
    sawtooth = 4,
    halfSinus = 5, // однополупериодный выпрямитель
    doubleHalfSinus = 6 //двуполупериодный выпрямитель
};

class CircuitWork {
private :
    struct ParamCircuit {
        double _C1; //< uF
        double _R1; //< kOhm
        double _R2; //< kOhm
        ParamCircuit() = delete;
        ParamCircuit(double C1, double R1, double R2);
    } *schemeParam;
    struct ParamVoltSource {
        double _E1;
        TypeSignal  _signalForm;
        ParamVoltSource() = delete;
        ParamVoltSource(double E1, enum TypeSignal signal);
    } *voltageSource;
    double stepTime;
    double curVoltageC;
    double totalTime;

    bool SW1;
    bool SW2;

    double frequency;

public :
    CircuitWork() = delete;
    CircuitWork(const ParamCircuit& valueElements, const ParamVoltSource& voltage);
    CircuitWork(double C1, double R1, double R2, double E1, TypeSignal signal);
    double getVoltageC(double curTime); //получение напряжения на конденсаторе в заданный момент времени функция в основном применяется для работы с переменными сигналами, т.е. ключи SW1, SW2 - замкнуты
    double getVoltageE1(double curTime) const; // получение напряжение источника сигнала в заданный момент времени
    double getVoltageCharge(double curTime);    //получение напряжения на конденсаторе в период заряда при U(0) = 0, в случае постоянного напряжения SW1 - замкнут, SW2 разомкнут
    double getVoltageDischarge(double curTime); //получение напряжения на конденсаторе в период разряда U(0) = ._E1, в случае постоянного напряжения SW1 - разомкнут, SW2 - замкнут
    ~CircuitWork();

    //альтернативная реализация (ИМХО более универсальная)
    bool toggle_SW1(); //переключение переключателя SW1 возвращает состояние
    bool status_SW1() const; //состоянBие переключателя SW1
    bool switch_SW1(bool on); //переключение SW1, (on == true) - замкнут, (on == false) - разомкнут
    bool toggle_SW2(); //переключение переключателя SW2 возвращает состояние
    bool status_SW2() const; //состояние переключателя SW2
    bool switch_SW2(bool on); //переключение SW2, (on == true) - замкнут, (on == false) - разомкнут

    void getVoltage(double curTime);
    void getVoltage(double curTime, bool statusSW1, bool statusSW2);

    double getCurrentVoltageC() const;

    //ещё одна альтернативная реализация
    std::vector<std::pair<double,double>> getSignalVolt() const; //возвращает вектор пар точек время, напряжение

    void setStepTime(double step);
    void setFrequency(double freq);
    void resetVoltageC(double value = 0.0);
};






#endif // RESEARCH_COND_H
