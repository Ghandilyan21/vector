#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <typename T>
class Vector
{
public:
    Vector();
    Vector(int size);
    Vector(const Vector<T>& rhs);
    ~Vector();
    int size();
    int copacity();
    bool empty();
    T at(int index);
    void push_back(T value);
    void pop_back();
    T& operator[](int index);
    Vector<T>& operator=(const Vector<T>& rhs);
    T* data();
    void clear();
    void insert(int index, T value);
private:
    int m_size;
    int m_copacity;
    T* m_arr;
    void resize();
};
#include "vector.cpp"
#endif