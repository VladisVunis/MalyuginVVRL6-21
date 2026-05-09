#include "ring_buffer.h"

RingBuffer::RingBuffer() {
    size = 16;
    buffer = new int [size];
    dataLen = 0;
    pBegin = 0;
    pEnd = pBegin;
}

RingBuffer::RingBuffer(int _size) {
    size = _size;
    buffer = new int [size];
    dataLen = 0;
    pBegin = 0;
    pEnd = pBegin;
}

RingBuffer::~RingBuffer() {
    delete [] buffer;
}

int RingBuffer::pop_front() {
    if (dataLen == 0) {
        return ErrorFilo::empty;
    }

    pBegin++;
    dataLen--;
    if (pBegin == size) {
        pBegin = 0;
    }

    return ErrorFilo::ok;
}

int RingBuffer::pop_back() {
    if (dataLen == 0) {
        return ErrorFilo::empty;
    }

    dataLen--;
    pEnd--;

    if (pEnd < 0) {
        pEnd = size - 1;
    }

    return ErrorFilo::ok;
}

int RingBuffer::push_back(int element) {
    if (dataLen == size) {	//?????
        return  ErrorFilo::full;
    }

    buffer[pEnd] = element;
    ++pEnd;
    dataLen++;

    if (pEnd == size) {
        pEnd = 0;
    }

    return ErrorFilo::ok;
}

int RingBuffer::push_front(int element) {
    if (dataLen == size) {
        return ErrorFilo::full;
    }

    --pBegin;
    if (pBegin < 0) {
        pBegin = size - 1;
    }
    buffer[pBegin] = element;
    dataLen++;

    return ErrorFilo::ok;
}

void RingBuffer::flush() {
    dataLen = 0;
}
