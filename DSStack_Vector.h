// Implement a stack based on an array
#ifndef DSStack_Vector_H
#define DSStack_Vector_H

using namespace std;
template <typename Object>
class DSStack_Vector {
private:
    int capacity;
    Object *array;
    int top;
    int size;
public:
    DSStack_Vector() {
        capacity = 2; // start with capacity 2
        array = new Object[capacity];
        top = -1;
        size = 0;
    }
    ~DSStack_Vector() {
        delete[] array;
    }
    //push
    void push(const Object data) {
        if (size == capacity) {
            // if array is full, double its capacity
            Object *new_array = new Object[capacity * 2];
            for (int i = 0; i < size; i++) {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
            capacity *= 2;
        }
        top++;
        array[top] = data;
        size++;
    }
    //pop
    void pop() {
        if (size == 0) {
            throw runtime_error("Stack underflow");
        }
        int data = array[top];
        top--;
        size--;
        // if size is less than 1/4 of capacity, halve its capacity
        if (size < capacity / 4 && capacity > 2) {
            Object *new_array = new Object[capacity / 2];
            for (int i = 0; i < size; i++) {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
            capacity /= 2;
        }
    }
    //is empty
    bool is_empty() {
        return (size == 0);
    }
    //peek(return what is at the top)
    const Object& peek() {
        if (size == 0) {
            throw runtime_error("Stack is empty");
        }
        return array[top];
    }
    //empty the stack
    void clear() {
        delete [] array;
        capacity = 2; // start with capacity 2
        array = new Object[capacity];
        top = -1;
        size = 0;
    }

};

#endif

