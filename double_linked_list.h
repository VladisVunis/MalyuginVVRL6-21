#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <vector>
#include <utility>

struct Data {
    std::vector<std::pair<double, double>> points;
};

struct Node {
    Data data;
    Node* prev;
    Node* next;

    Node(const Data* d);
};

class DoubleLinkedList {
private:
    Node* Head;
    Node* Tail;
    int countNodes;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void push_back(const Data* d);
    void push_front(const Data* d);

    std::vector<std::pair<double, double>> get_Node(int num_node) const;

    int getCountNodes() const;

    void pop_front();
    void pop_back();

    void insert(const Data* d, int num_node);
};

#endif // DOUBLE_LINKED_LIST_H
