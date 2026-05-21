#include <iostream>

#define NAME 1// RK = 1/HW = 2/ SW = 3
#define COUNT 2 // номер работы
#define NUMBER 1 // номер задания

/*enum NAME{
    SW = 3,
    RK = 1,
    HW = 3,
};*/

#include "test.h"

#if NAME == 1 && COUNT == 1
#include "box.h"
#include "fraction.h"
#elif NAME == 1 && COUNT == 2
#include "rk_2.h"

#include <iostream>
#include <vector>
#include <utility>
#elif NAME == 2 && COUNT == 1
#include "sorts.h"
#include "HW1.h"
#elif NAME == 3 && COUNT == 6
#include "ring_buffer.h"
#include "filo.h"
#include "task_filo.h"
#include "test_ring_buffer.h"
#elif NAME == 3 && COUNT == 5
#include "bit_operations.h"
#include "box.h"
#elif  NAME == 3 && COUNT == 4
#include "fraction.h"
#include "box.h"
#elif NAME == 3 && COUNT == 3
#include "bit_operations.h"
#include "file_operations.h"
#elif NAME == 3 && COUNT == 2
#include "bit_operations.h"
#elif NAME == 3 && COUNT == 1
#include "sorts.h"
#elif NAME == 2 && COUNT == 2
#include "verdana_8_font.h"
#include "parse_fonts.h"
#include "research_cond.h"
#include "gnuplot.h"

struct ProgramOptions {
    double R1 = 100.0;      // кОм
    double R2 = 1.0;        // кОм
    double C1 = 100.0;      // мкФ
    double E1 = 10.0;       // В

    double step = 0.01;
    double freq = 1.0;

    double T = 8.0 * 3.14159265358979323846;

    TypeSignal signal = TypeSignal::constV;

    bool charge = true;
    bool discharge = true;

    std::string jpegFile = "";
};

bool startsWith(const std::string& str, const std::string& prefix) {
    return str.rfind(prefix, 0) == 0;
}

double parseResistanceToKOhm(const std::string& text) {
    char last = text.back();
    double value = std::atof(text.c_str());

    if (last == 'k') {
        return value;
    }

    if (last == 'M') {
        return value * 1000.0;
    }

    return value / 1000.0;
}

double parseCapacitanceToUF(const std::string& text) {
    char last = text.back();
    double value = std::atof(text.c_str());

    if (last == 'u') {
        return value;
    }

    if (last == 'n') {
        return value / 1000.0;
    }

    if (last == 'p') {
        return value / 1000000.0;
    }

    return value;
}

TypeSignal parseSignal(const std::string& text) {
    if (text == "constV") {
        return TypeSignal::constV;
    }

    if (text == "sin" || text == "sinus") {
        return TypeSignal::sinus;
    }

    if (text == "meandr") {
        return TypeSignal::meandr;
    }

    if (text == "triangle") {
        return TypeSignal::triangle;
    }

    if (text == "sawtooth") {
        return TypeSignal::sawtooth;
    }

    if (text == "halfSin" || text == "halfSinus") {
        return TypeSignal::halfSinus;
    }

    if (text == "rectSin" || text == "doubleHalfSinus") {
        return TypeSignal::doubleHalfSinus;
    }

    return TypeSignal::constV;
}

bool parseBool(const std::string& text) {
    if (text == "true" || text == "1") {
        return true;
    }

    return false;
}

void parseArguments(int argc, char* argv[], ProgramOptions& opt) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (startsWith(arg, "-R1=")) {
            opt.R1 = parseResistanceToKOhm(arg.substr(4));
        }
        else if (startsWith(arg, "-R2=")) {
            opt.R2 = parseResistanceToKOhm(arg.substr(4));
        }
        else if (startsWith(arg, "-C1=")) {
            opt.C1 = parseCapacitanceToUF(arg.substr(4));
        }
        else if (startsWith(arg, "-E1=")) {
            opt.E1 = std::atof(arg.substr(4).c_str());
        }
        else if (startsWith(arg, "--signal=")) {
            opt.signal = parseSignal(arg.substr(9));
        }
        else if (startsWith(arg, "--step=")) {
            opt.step = std::atof(arg.substr(7).c_str());
        }
        else if (startsWith(arg, "--freq=")) {
            opt.freq = std::atof(arg.substr(7).c_str());
        }
        else if (startsWith(arg, "-T=")) {
            opt.T = std::atof(arg.substr(3).c_str());
        }
        else if (startsWith(arg, "--jpeg=")) {
            opt.jpegFile = arg.substr(7);
        }
        else if (startsWith(arg, "--charge=")) {
            opt.charge = parseBool(arg.substr(9));
        }
        else if (startsWith(arg, "--discharge=")) {
            opt.discharge = parseBool(arg.substr(12));
        }
    }
}

std::vector<std::pair<double, double>>
makeChargePoints(CircuitWork& circuit, double T, double step) {
    std::vector<std::pair<double, double>> points;

    for (double t = 0.0; t <= T; t += step) {
        double voltage = circuit.getVoltageCharge(t);
        points.push_back({t, voltage});
    }

    return points;
}

std::vector<std::pair<double, double>>
makeDischargePoints(CircuitWork& circuit, double T, double step) {
    std::vector<std::pair<double, double>> points;

    for (double t = 0.0; t <= T; t += step) {
        double voltage = circuit.getVoltageDischarge(t);
        points.push_back({t, voltage});
    }

    return points;
}

std::vector<std::pair<double, double>>
makeSignalPoints(CircuitWork& circuit, double T, double step) {
    std::vector<std::pair<double, double>> points;

    for (double t = 0.0; t <= T; t += step) {
        double voltage = circuit.getVoltageE1(t);
        points.push_back({t, voltage});
    }

    return points;
}

std::vector<std::pair<double, double>>
makeCapacitorPoints(CircuitWork& circuit, double T, double step) {
    std::vector<std::pair<double, double>> points;

    circuit.resetVoltageC(0.0);

    for (double t = 0.0; t <= T; t += step) {
        circuit.getVoltage(t, true, true);

        double voltage = circuit.getCurrentVoltageC();

        points.push_back({t, voltage});
    }

    return points;
}

#endif

#if NAME == 2 && COUNT == 2 && NUMBER == 1
int main(int argc, char* argv[]) {
    ProgramOptions opt;

    parseArguments(argc, argv, opt);

    CircuitWork circuit(
        opt.C1,
        opt.R1,
        opt.R2,
        opt.E1,
        opt.signal
        );

    circuit.setStepTime(opt.step);
    circuit.setFrequency(opt.freq);

    Gnuplot gp;

    if (!gp.isOpen()) {
        std::cout << "Gnuplot не открылся" << std::endl;
        return 1;
    }

    if (opt.signal == TypeSignal::constV) {
        std::vector<std::pair<double, double>> chargePoints;
        std::vector<std::pair<double, double>> dischargePoints;

        if (opt.charge == true) {
            chargePoints = makeChargePoints(circuit, opt.T, opt.step);
        }

        if (opt.discharge == true) {
            dischargePoints = makeDischargePoints(circuit, opt.T, opt.step);
        }

        if (!opt.jpegFile.empty()) {
            gp.saveJpeg(opt.jpegFile);

            if (opt.charge && opt.discharge) {
                gp.plotTwoPoints(chargePoints, "Charge", dischargePoints, "Discharge", "t, sec", "U, V");
            }
            else if (opt.charge) {
                gp.plotPoints(chargePoints, "Charge", "t, sec", "U, V");
            }
            else if (opt.discharge) {
                gp.plotPoints(dischargePoints, "Discharge", "t, sec", "U, V");
            }

            gp.command("set output");
        }

        gp.showWindow();

        if (opt.charge && opt.discharge) {
            gp.plotTwoPoints(chargePoints, "Charge", dischargePoints, "Discharge", "t, sec", "U, V");
        }
        else if (opt.charge) {
            gp.plotPoints(chargePoints, "Charge", "t, sec", "U, V");
        }
        else if (opt.discharge) {
            gp.plotPoints(dischargePoints, "Discharge", "t, sec", "U, V");
        }
    }
    else {
        double T = 3.0 / opt.freq;

        std::vector<std::pair<double, double>> signalPoints =
            makeSignalPoints(circuit, T, opt.step);

        std::vector<std::pair<double, double>> capacitorPoints =
            makeCapacitorPoints(circuit, T, opt.step);

        if (!opt.jpegFile.empty()) {
            gp.saveJpeg(opt.jpegFile);

            gp.plotTwoPoints(signalPoints, "E1(t)", capacitorPoints, "Uc(t)", "t, sec", "U, V");

            gp.command("set output");
        }

        gp.showWindow();

        gp.plotTwoPoints(signalPoints, "E1(t)", capacitorPoints, "Uc(t)", "t, sec", "U, V");
    }

    return 0;
}
#endif
#if NAME == 2 && COUNT == 1
int main(int argc, char* argv[])
{
    int minSize = 50;
    int maxSize = 200000;
    int stepSize = 0;
    int maxTime = 1000;

    for (int i = 1; i < argc; i++) {
        std::string flag = argv[i];

        if (flag == "--min_size" && i + 1 < argc) {
            minSize = std::atoi(argv[i + 1]);
            i++;
        }
        else if (flag == "--max_size" && i + 1 < argc) {
            maxSize = std::atoi(argv[i + 1]);
            i++;
        }
        else if (flag == "--step_size" && i + 1 < argc) {
            stepSize = std::atoi(argv[i + 1]);
            i++;
        }
        else if (flag == "--max_time" && i + 1 < argc) {
            maxTime = std::atoi(argv[i + 1]);
            i++;
        }
    }

    writeTOP("result");
    bool useBubble = true;
    bool useSelection = true;
    bool useInsertion = true;
    bool useMerge = true;
    bool useQuick = true;
    bool useShell = true;
    bool useCount = true;

        for(int j = minSize;j < maxSize; ){

            for(int i = 1; i < 9; i++ ){
                switch(i){
                case 1:{
                    char* sizeStr = convertIntToStr(j);
                    writeStringToFile("result" , sizeStr);
                    delete [] sizeStr;
                    break;
                }
                case 2: {
                    if (useBubble == false) {
                        writeStringToFile("result", "---");
                        break;
                    }

                    int* ar = new int [j];
                    randomFillAr(ar, j);
                    double time1 = getTime(meas::milli);
                    bubbleSort(ar, j, ascending);
                    double time2 = getTime(meas::milli);
                    delete [] ar;
                    double result = time2 - time1;

                    if (result > maxTime) {
                        useBubble = false;
                        writeStringToFile("result", "---");
                    } else {
                        char* time = convertDoubleToStr(result);
                        writeStringToFile("result", time);
                        delete[] time;
                    }

                    break;
                }
                case 3:{
                    if (useSelection == false) {
                        writeStringToFile("result", "---");
                        break;
                    }

                    int* ar = new int [j];
                    randomFillAr(ar, j);
                    double time1 = getTime(meas::milli);
                    selectionSort(ar, j, ascending);
                    double time2 = getTime(meas::milli);
                    delete [] ar;
                    double result = time2 - time1;

                    if (result > maxTime) {
                        useSelection = false;
                        writeStringToFile("result", "---");
                    } else {
                        char* time = convertDoubleToStr(result);
                        writeStringToFile("result", time);
                        delete[] time;
                    }

                    break;
                }
                case 4:{
                    if (useInsertion == false) {
                        writeStringToFile("result", "---");
                        break;
                    }

                    int* ar = new int [j];
                    randomFillAr(ar, j);
                    double time1 = getTime(meas::milli);
                    insertionSort(ar, j, ascending);
                    double time2 = getTime(meas::milli);
                    delete [] ar;
                    double result = time2 - time1;

                    if (result > maxTime) {
                        useInsertion = false;
                        writeStringToFile("result", "---");
                    } else {
                        char* time = convertDoubleToStr(result);
                        writeStringToFile("result", time);
                        delete[] time;
                    }

                    break;
                }
                case 5:{
                    if (useMerge == false) {
                        writeStringToFile("result", "---");
                        break;
                    }
                    int* ar = new int [j];
                    randomFillAr(ar, j);
                    double time1 = getTime(meas::milli);
                    mergeSort(ar, j, ascending);
                    double time2 = getTime(meas::milli);
                    delete [] ar;
                    double result = time2 - time1;

                    if (result > maxTime) {
                        useMerge = false;
                        writeStringToFile("result", "---");
                    } else {
                        char* time = convertDoubleToStr(result);
                        writeStringToFile("result", time);
                        delete[] time;
                    }

                    break;
                }
                case 6:{
                    if (useQuick == false) {
                        writeStringToFile("result", "---");
                        break;
                    }
                    int* ar = new int [j];
                    randomFillAr(ar, j);
                    double time1 = getTime(meas::milli);
                    quickSort(ar, j, ascending);
                    double time2 = getTime(meas::milli);
                    delete [] ar;
                    double result = time2 - time1;

                    if (result > maxTime) {
                        useQuick = false;
                        writeStringToFile("result", "---");
                    } else {
                        char* time = convertDoubleToStr(result);
                        writeStringToFile("result", time);
                        delete[] time;
                    }

                    break;
                }
                case 7:{
                    if (useShell == false) {
                        writeStringToFile("result", "---");
                        break;
                    }
                    int* ar = new int [j];
                    randomFillAr(ar, j);
                    double time1 = getTime(meas::milli);
                    sortShell(ar, j, ascending);
                    double time2 = getTime(meas::milli);
                    delete [] ar;
                    double result = time2 - time1;

                    if (result > maxTime) {
                        useShell = false;
                        writeStringToFile("result", "---");
                    } else {
                        char* time = convertDoubleToStr(result);
                        writeStringToFile("result", time);
                        delete[] time;
                    }

                    break;
                }
                case 8:{
                    if (useCount == false) {
                        writeStringToFile("result", "---");
                        break;
                    }
                    int* ar = new int [j];
                    randomFillAr(ar, j);
                    double time1 = getTime(meas::milli);
                    countSort(ar, j, ascending);
                    double time2 = getTime(meas::milli);
                    delete [] ar;
                    double result = time2 - time1;

                    if (result > maxTime) {
                        useCount = false;
                        writeStringToFile("result", "---");
                    } else {
                        char* time = convertDoubleToStr(result);
                        writeStringToFile("result", time);
                        delete[] time;
                    }

                    break;
                }
                }
            }

            if(stepSize == 0){
                j +=getStep(j);
            }
            else{
                j += stepSize;
            }

        }



    return 0;
}
#endif



#if NAME == 3 || NAME == 1 || (NAME == 2 && COUNT == 2 && NUMBER == 2)
int main()
{
#if NAME == 1 && COUNT == 2
    ProcessPulses pulses("current_pulse.bin");

    std::cout << "Count: " << pulses.getCountPulse() << std::endl;

    std::vector<std::pair<double, double>> pulse = pulses.getPulse(2, false);

    Gnuplot gp;

    if (!gp.isOpen()) {
        std::cout << "Gnuplot не открылся" << std::endl;
        return 1;
    }

    gp.buildPulse(pulse, SaveTo::show);

    std::cout << "График построен" << std::endl;

    return 0;
#endif

#if NAME == 2 && COUNT == 2 && NUMBER == 2
parse_font('9', 'L', '~');
#endif

#if NAME == 3 && COUNT == 6 && NUMBER == 2

RUN_TEST(test_ring_buffer_empty);
RUN_TEST(test_ring_buffer_push_back_full);
RUN_TEST(test_ring_buffer_get_front_full);

#endif

#if NAME == 3 && COUNT == 6 && NUMBER == 4

bool res;
res = test_brackets("()(){<<>>[]}");
std::cout << res << std::endl;

#endif
#if NAME == 3 && COUNT == 6 && NUMBER == 3

    FILO filo(8);

    for (int i = 0; i < 8; i++) {
        if (filo.putToEnd(i + 1) != ErrorFilo::ok) {
            ASSERT(0);
        }
    }

    filo.showElements();

    ASSERT(filo.putToEnd(10) == ErrorFilo::full);

    filo.flush();

    for (int i = 0; i < 3; filo.getFromEnd(nullptr), i++);

    filo.showElements();

    while(filo.getFromEnd(nullptr) != ErrorFilo::empty);

    filo.showElements();

#endif

#if NAME == 3 && COUNT == 5 && NUMBER == 1

        Box* temp[10];
        temp[0] = new Box(10, 12, 13);
        std::cout << *temp[0]; // [1] = {10, 12, 13} = 1560
        temp[1] = new Box(1, 2, 3);
        std::cout << *temp[1]; // [2] = {1, 2, 3} = 6
        delete temp[1];
        temp[2] = new Box(1, 2, 3);
        std::cout << *temp[2]; // [2] = {1, 2, 3} = 6
        delete temp[0];
        temp[3] = new Box(1, 2, 3);
        std::cout << *temp[3]; // [3] = {1, 2, 3} = 6
        temp[0] = new Box(2, 3, 4);
        std::cout << *temp[0]; // [4] = {2, 3, 4} = 24
        Box temp_1(1,2,2);
        std::cout << temp_1; // [5] = {1, 2, 2} = 4
        delete temp[0];
        delete temp[3];
        delete temp[2];

#endif

#if NAME == 3 && COUNT == 5 && NUMBER == 2

    int a = 0x101;
    bool res0 = isPalindromNumber(a);
    cout << res0 << endl;

#endif

#if NAME == 1 && COUNT == 1 && NUMBER == 2

    Fraction fr1(10, 20);
    Fraction fr2(-5, 7);
    std::cout << sum(fr1, fr2) << std::endl;
    std::cout << sub(fr1, fr2) << std::endl;
    std::cout << div(fr1,fr2) << std::endl;
    std::cout << mul(fr1, fr2) << std::endl;

#endif

#if NAME == 1 && COUNT == 1 && NUMBER == 1

    const struct Box temp(15);
    std::cout << temp;

    const struct Box temp1;
    std::cout << temp1;

    const struct Box temp2(5,10,11);
    std::cout << temp2;

#endif

#if NAME == 3 && COUNT == 4 && NUMBER == 2

    Fraction test(10, 15);
    int res = fracReduction(test);
    if (res == -1) {
        std::cerr << "errror..." << std::endl;
    }
    std::cout << test._numerator << "/" << test._denominator << std::endl;

#endif

#if NAME == 3 && COUNT == 4 && NUMBER == 1

    Box box;
    Box* temp = new Box();

    temp->_len = 1;
    temp->_width = 2;
    temp->_height = 3;
    temp->_color = 0x00FF00FF;
    writeToFile("STR",*temp );
    delete temp;
    temp = nullptr;
    Box* temp1 = new Box();
    readFromFile("STR", *temp1);
    cout << temp1->_len <<endl;
    cout << temp1->_width <<endl;
    cout << temp1->_height <<endl;
    cout << std::hex << temp1->_color <<endl;
    delete temp1;
    temp1 = nullptr;

#endif
#if NAME == 3 && COUNT == 3 && NUMBER == 3

    srand(time(nullptr));
    fillFile("set", 10, 20, '\t', 7, 12);

#endif

#if NAME == 3 && COUNT == 3 && NUMBER == 2

    int number = 0x80000001;

    setBit(&number, 8);
    cout << hex << number << endl;



    clearBit(&number, 0);
    cout << hex << number << endl;

#endif

#if NAME == 3 && COUNT == 3 && NUMBER == 1

    unsigned int ar[4] = {0x80000001u, 0x00, 0x80, 0x10};
    int size = 4;
    bool f = true;

    for(int i = 0; i < 4; i++){
        std::cout << "x"<< i+1<< " = " << std::hex << ar[i] << std::endl;
    }

    std::cout << std::endl;

    cycleShiftArray(ar, 4, 1, f);
    for(int i = 0; i < 4; i++){
        std::cout << "x"<< i+1<< " = " << std::hex << ar[i] << std::endl;
    }

#endif

#if NAME == 3 && COUNT == 2 && NUMBER == 1

    unsigned int w = 0xFFAABBCC;
    swapHalfWord(&w);
    cout << hex << w << endl;

#endif

#if NAME == 3 && COUNT == 2 && NUMBER == 2

    unsigned int Pnumber = 0x80000801;
    cycleShift(&Pnumber, 3, 0);
    cout << hex << Pnumber/2 << endl;

#endif

#if NAME == 3 && COUNT == 2 && NUMBER == 3

    int ar[5] = { 0x0FFFFFFF, (int) 0xFFFFFFFF, 0x00, 0x0FFFFFFF};
    int index = 0;
    index = getMaxBit(ar,4);
    cout << index<< endl;

#endif

#if NAME == 3 && COUNT == 2 && NUMBER == 4

    int num = -10;
    unsigned char amount = getCount1Bit(num);
    cout << (int)amount << endl;

#endif

#if NAME == 3 && COUNT == 1 && (NUMBER == 1 || NUMBER == 2)

    int arr[] = {110, 6, -10, 4 ,-22, 77};
    selectionSort(arr, 6, true);
    for(int i = 0;i < 6; i++){
        std::cout<<arr[i]<<" ";
    }

    std::cout<<"\n";
    int v = isSorted(arr, 6);
    std::cout<<v<<"\n";

#endif

    return 0;

}
#endif
