#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <typename T>
class Vector
{
public:
    Vector();
    explicit Vector(int size);
    Vector(const Vector<T>& rhs);
    Vector(std::initializer_list<T> list);
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
    void shrink_to_fit();
    T& front();
    T& back();
    int find(const T& val);
    void unique();
    void reverse();
    void sort();
    void erase(size_t index);
    void erase(size_t index, size_t count);
private:
    size_t m_size;
    size_t m_copacity;
    T* m_arr;
    void resize();
};
#include "vector.cpp"
#endif
