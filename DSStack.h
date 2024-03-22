// Implement a stack based on an DSList
#ifndef DSStack_H
#define DSStack_H

#include "DSList.h"

template <typename Object>
class DSStack {
private:
    DSList<Object> list;
public:
    //push
    void push(Object x) {
        list.push_front(x);
    }
    //pop
    void pop() {
        list.pop_front();
    }
    //is empty
    bool is_empty() {
        return (list.is_empty());
    }
    //peek(return what is at the top)
    const Object& peek() {
        if (!is_empty()) {
            return (list.front());
        } else {
            throw std::out_of_range("Stack is empty");
        }
    }
    //size(return size of the stack)
    size_t size() {
        return list.size();
    }
    //empty the stack
    void clear() {
        int size = list.size();
        for (size_t i = 0; i < size; i++) {
            pop();
        }
    }
};

#endif