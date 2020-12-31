#pragma once
#include<stdexcept>

using namespace std;

template<typename> class SLinkedList;

template <typename E>
class SNode {
private:
    E elem;
    SNode<E>* next;
    friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList {
public:
    SLinkedList() :head(NULL) { };
    ~SLinkedList() { while (!empty()) removeFront(); }
    bool empty() const { return head == NULL; }
    const E& front() const { return head->elem; }
    void addFront(const E& e) {
    SNode<E>* v = new SNode<E>;
    v->elem = e;
    v->next = head;
    head = v;
}
    void removeFront() {
    SNode<E>* old = head;
    head = old->next;
    delete old;
}
private:
    SNode<E>* head;
};

template <typename E>
class LinkedStack {
public:
    LinkedStack() : S(), n(0) { }
    int size() const { return n; }
    bool empty() const { return n == 0; }
    const E& top() const throw(runtime_error) {
    if (empty()) throw runtime_error("Top of empty stack");
    return S.front();
}
    void push(const E& e) {
    ++n;
    S.addFront(e);
}
    void pop() throw(runtime_error) {
    if (empty()) throw runtime_error("Pop from empty stack");
    --n;
    S.removeFront();
}
private:
    SLinkedList<E> S;
    int n;
};
