#ifndef RING_BUFFER_H
#define RING_BUFFER_H

enum ErrorFilo {
    ok = 0,
    empty = 1,
    full = 2,
};

class RingBuffer {
private :
    int* buffer;
    int size;
    int dataLen;

    int pBegin;
    int pEnd;

public:
    RingBuffer();
    RingBuffer(int);
    ~RingBuffer();

    int pop_front();
    int pop_back();
    int push_front(int element);
    int push_back(int element);
    int get_front(int* element);
    int get_back(int* element);

    void flush();
    int resize(int new_size);	//SW_6
};

#endif // RING_BUFFER_H
