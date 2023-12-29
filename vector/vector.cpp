#include "vector.h"

template <typename T>
Vector<T>::Vector()
    :
        m_size{},
        m_copacity{},
        m_arr{nullptr}
{
    //std::cout << "Default ctor" << std::endl;
}
template <typename T>
Vector<T>::Vector(int size)
    :
        m_size{size},
        m_copacity{m_size},
        m_arr{new T[m_size]}
{
    //std::cout << "Param ctor" << std::endl;

}
template <typename T>
Vector<T>::Vector(const Vector<T>& rhs)
{
    m_size = rhs.m_size;
    m_copacity = rhs.m_copacity;
    m_arr = new T[m_size];
    for (size_t i = 0; i < m_size; ++i)
    {
        m_arr[i] = rhs.m_arr[i];
    }
    //std::cout << "Copy ctor" << std::endl;
}
template <typename T>
Vector<T>::Vector(std::initializer_list<T> list)
    :
        m_size{list.size()},
        m_copacity{m_size},
        m_arr{new T[m_copacity]}
{
    for(int i = 0; auto& val : list)
    {
        m_arr[i] = val;
        ++i;
    }
     
}

template <typename T>
Vector<T>::~Vector()
{
    delete [] m_arr;
}
template <typename T>
int Vector<T>::size()
{
    return m_size;
}
template <typename T>
int Vector<T>::copacity()
{
    return m_copacity;
}
template <typename T>
bool Vector<T>::empty()
{
    return !m_size;
}
template <typename T>
T Vector<T>::at(int index)
{
    if (index < 0 || index >= m_size)
    {
        throw std::invalid_argument("");
    }
    return m_arr[index];
}
template <typename T>
void Vector<T>::push_back(T value)
{
    if (m_size == m_copacity)
    {
        resize();
    }
    m_arr[m_size] = value;
    ++m_size;
}
template <typename T>
void Vector<T>::resize()
{
    m_copacity = m_copacity == 0? 1 : m_copacity *= 2;
    T* tmp = new T[m_copacity];
    for (size_t i = 0; i < m_size; ++i)
    {
        tmp[i] = m_arr[i];
    }
    delete [] m_arr;
    m_arr = tmp;
}
template <typename T>
void Vector<T>::pop_back()
{
    if (m_size > 0)
    {
        --m_size;
    }
    else
    {
        throw std::exception();
    }
}
template <typename T>
T& Vector<T>::operator[](int index)
{
    if (index < 0 || index >= m_size)
    {
 
        throw std::invalid_argument("");
    }
    return m_arr[index];
}
template <typename T>
T* Vector<T>::data()
{
    return m_arr;
}
template <typename T>
void Vector<T>::clear()
{
    delete [] m_arr;
    m_size = 0;
    m_copacity = 0;
    m_arr = nullptr;
}
template <typename T>
void Vector<T>::insert(int index, T value)
{
    if (index < 0 || index >= m_size)
    {
        throw std::invalid_argument("");
    }
    if (m_size == m_copacity)
    {
        resize();
    }
    for (size_t i = m_size; i >= index; --i)
    {
        m_arr[i + 1] = m_arr[i];
    }
    m_arr[index] = value;
    ++m_size;
}
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    delete [] m_arr;
    m_size = rhs.m_size;
    m_copacity = rhs.m_copacity;
    T* tmp = new T[m_size];
    for (size_t i = 0; i < m_size; ++i)
    {
        tmp[i] = rhs.m_arr[i];
    }
    m_arr = tmp;
    std::cout << "Copy assignment" << std::endl;
    return *this;
}

template<typename T>
void Vector<T>::shrink_to_fit()
{
    m_copacity = m_size;
    T* tmp = new T[m_copacity];
    for (size_t i = 0; i < m_size; ++i)
    {
        tmp[i] = m_arr[i];
    }
    delete [] m_arr;
    m_arr = tmp;
}
template<typename T>
T& Vector<T>::front()
{
    return m_arr[0];
}
template<typename T>
T& Vector<T>::back()
{
    return m_arr[m_size];
}

template<typename T>
int Vector<T>::find(const T& value)
{
    for (size_t i = 0; i < m_size; ++i)
    {
        if (m_arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

template<typename T>
void Vector<T>::reverse()
{
    if (m_size <= 1)
    {
        return;
    }
    
    int i = 0;
    int j = m_size - 1;
    while (i < j)
    {
        T tmp = m_arr[i];
        m_arr[i] = m_arr[j];
        m_arr[j] = tmp;
        ++i;
        --j;
    }
}

template<typename T>
void Vector<T>::sort()
{
    if (m_size <= 1)
    {
        return;
    }
    for (size_t i = 0; i < m_size; ++i)
    {
        bool flag = true;
        for (size_t j = 0; j < m_size - 1 - i; ++j)
        {
            if (m_arr[j + 1] < m_arr[j])
            {
                std::swap(m_arr[j], m_arr[j + 1]);
                flag = false;
            } 
        }
        if (flag)
        {
            break;
        }   
    }
}
template <typename T>
void Vector<T>::erase(size_t index)
{
    for (size_t i = index; i < m_size - 1; ++i)
    {
        m_arr[i] = m_arr[i + 1];
    }
    --m_size;
}
template <typename T>
void Vector<T>::unique()
{
    for (size_t i = 0; i < m_size; ++i)
    {
        for (size_t j = i + 1; j < m_size; ++j)
        {
            if (m_arr[i] == m_arr[j])
            {
                erase(j);
                --j;
            }
        }
    }
}
template<typename T>
void Vector<T>::erase(size_t index, size_t count)
{
    if (index + count > m_size)
    {
        throw std::invalid_argument(" ");
    }
    
    for (size_t i = index; i < m_size - count - 1; ++i)
    {
        m_arr[i] = m_arr[i + count];
    }
    m_size -= count;
}
