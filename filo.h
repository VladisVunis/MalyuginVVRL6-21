#ifndef FILO_H
#define FILO_H

class FILO {
private :
    int* buffer;
    int size;
    int dataLen;

public :
    FILO();
    FILO(int size);
    ~FILO();

    int putToEnd(int element);
    int getFromEnd(int* element);
    int showLastElement(int* element) const;
    void flush();

    void showElements() const;
};

#endif // FILO_H
