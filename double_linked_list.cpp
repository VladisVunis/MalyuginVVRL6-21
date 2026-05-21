#include "double_linked_list.h"

Node::Node(const Data* d) {
    if (d != nullptr) {
        data = *d;
    }

    prev = nullptr;
    next = nullptr;
}

DoubleLinkedList::DoubleLinkedList() {
    Head = nullptr;
    Tail = nullptr;
    countNodes = 0;
}

DoubleLinkedList::~DoubleLinkedList() {
    while (countNodes > 0) {
        pop_front();
    }
}

void DoubleLinkedList::push_back(const Data* d) {
    if (d == nullptr) {
        return;
    }

    Node* newNode = new Node(d);

    if (countNodes == 0) {
        Head = newNode;
        Tail = newNode;
    } else {
        Tail->next = newNode;
        newNode->prev = Tail;
        Tail = newNode;
    }

    countNodes++;
}

void DoubleLinkedList::push_front(const Data* d) {
    if (d == nullptr) {
        return;
    }

    Node* newNode = new Node(d);

    if (countNodes == 0) {
        Head = newNode;
        Tail = newNode;
    } else {
        newNode->next = Head;
        Head->prev = newNode;
        Head = newNode;
    }

    countNodes++;
}

int DoubleLinkedList::getCountNodes() const {
    return countNodes;
}

std::vector<std::pair<double, double>> DoubleLinkedList::get_Node(int num_node) const {
    std::vector<std::pair<double, double>> empty;

    if (countNodes == 0) {
        return empty;
    }

    if (num_node < 0) {
        return Head->data.points;
    }

    if (num_node >= countNodes) {
        return Tail->data.points;
    }

    Node* current = Head;

    for (int i = 0; i < num_node; i++) {
        current = current->next;
    }

    return current->data.points;
}

void DoubleLinkedList::pop_front() {
    if (countNodes == 0) {
        return;
    }

    Node* oldHead = Head;

    if (countNodes == 1) {
        Head = nullptr;
        Tail = nullptr;
    } else {
        Head = Head->next;
        Head->prev = nullptr;
    }

    delete oldHead;
    countNodes--;
}

void DoubleLinkedList::pop_back() {
    if (countNodes == 0) {
        return;
    }

    Node* oldTail = Tail;

    if (countNodes == 1) {
        Head = nullptr;
        Tail = nullptr;
    } else {
        Tail = Tail->prev;
        Tail->next = nullptr;
    }

    delete oldTail;
    countNodes--;
}

void DoubleLinkedList::insert(const Data* d, int num_node) {
    if (d == nullptr) {
        return;
    }

    if (num_node <= 0) {
        push_front(d);
        return;
    }

    if (num_node >= countNodes) {
        push_back(d);
        return;
    }

    Node* current = Head;

    for (int i = 0; i < num_node; i++) {
        current = current->next;
    }

    Node* newNode = new Node(d);
    Node* left = current->prev;

    left->next = newNode;
    newNode->prev = left;

    newNode->next = current;
    current->prev = newNode;

    countNodes++;
}
