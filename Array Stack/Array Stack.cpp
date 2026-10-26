// Array Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename V>
class ArrayStack {
private:
    int _t;
    V* _Array;
    int _capacity;
public:
    ArrayStack(const int capacity) {
        _capacity = capacity;
        _Array = new V[capacity];
        _t = -1;

    }
    bool empty() {
        return _t == -1;

    }
    void Push(const V& value) {
        if (_t == _capacity - 1) {
            throw invalid_argument("Stack is Full");
        }
        else {
            _Array[++_t] = value;
        }
    }

    void Pop() {
        if (empty()) {
            throw invalid_argument("Stack is Empty ");
        }
        --_t;
    }


    V top() {
        if (!empty()) {
            return _Array[_t];
        }
        else {
            throw invalid_argument("Stack is Empty ");
        }
    }

    int size() {
        return _t + 1;
    }

    void traverse() {
        for (int i = 0; i <= _t; i++) {
            cout<< _Array[i];
        }
    }
};



int main()
{
    ArrayStack<int> numbers(10);
    numbers.Push(3);
    numbers.Push(4);
    numbers.Push(6);
    numbers.Pop();
    numbers.traverse();
}