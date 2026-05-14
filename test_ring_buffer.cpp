#include "test_ring_buffer.h"

void test_ring_buffer_empty() {
    RingBuffer buffer(3);

    ASSERT(buffer.pop_front() == ErrorFilo::empty);
    ASSERT(buffer.pop_back() == ErrorFilo::empty);
}

void test_ring_buffer_push_back_full() {
    RingBuffer buffer(3);

    ASSERT(buffer.push_back(1) == ErrorFilo::ok);
    ASSERT(buffer.push_back(2) == ErrorFilo::ok);
    ASSERT(buffer.push_back(3) == ErrorFilo::ok);
    ASSERT(buffer.push_back(4) == ErrorFilo::full);
}

void test_ring_buffer_get_front_full(){

    RingBuffer buffer(3);

    int value;

    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);

    buffer.get_front(&value);
    ASSERT_EQUAL(1, value);

    buffer.get_front(&value);
    ASSERT_EQUAL(2, value);

    buffer.get_front(&value);
    ASSERT_EQUAL(3, value);


}
