#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <typename T>
class Vector
{
public:
    using value_type = T;
    using size_type = size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator = pointer;
    using const_iterator = const_pointer;
public:
    Vector();
    explicit Vector(size_type size);
    Vector(const Vector<value_type>& rhs);
    Vector(std::initializer_list<value_type> list);
    Vector(Vector<value_type>&& rhs);
    Vector(size_type count, value_type value);
    ~Vector();
    size_type size() const;
    size_type copacity() const;
    bool empty() const;
    reference at(size_type index);
    const_reference at(size_type index) const;
    void push_back(value_type value);
    void pop_back();
    reference operator[](size_type index) noexcept;
    const_reference operator[](size_type index) const noexcept;
    const Vector<value_type>& operator=(const Vector<value_type>& rhs);
    const Vector<value_type>& operator=(Vector<value_type>&& rhs);
    pointer data();
    const_pointer data() const;
    void clear() noexcept;
    iterator insert(iterator it, value_type value); // porcel +
    void shrink_to_fit();
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    pointer find(const_reference val);
    void unique();
    void reverse();
    void sort();
    void erase(iterator it); // porcel ++
    void erase(iterator it1, iterator it2); // ++
    void assign(size_type count, value_type value);
    iterator begin(); 
    iterator end(); 
private:
    size_type m_size;
    size_type m_copacity;
    pointer m_arr;
    void resize();
};
#include "vector.cpp"
#endif
