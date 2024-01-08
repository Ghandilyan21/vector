#include "vector.h"
template <typename value_type>
Vector<value_type>::Vector()
    :
        m_size{},
        m_copacity{},
        m_arr{nullptr}
{
    
}
template <typename value_type>
Vector<value_type>::Vector(size_type size)
    :
        m_size{size},
        m_copacity{m_size},
        m_arr{new value_type[m_size]}
{

}
template <typename value_type>
Vector<value_type>::Vector(const Vector<value_type>& rhs)
{
    m_size = rhs.m_size;
    m_copacity = rhs.m_copacity;
    m_arr = new value_type[m_size];
    for (size_type i = 0; i < m_size; ++i)
    {
        m_arr[i] = rhs.m_arr[i];
    }
}
template <typename value_type>
Vector<value_type>::Vector(std::initializer_list<value_type> list)
    :
        m_size{list.size()},
        m_copacity{m_size},
        m_arr{new value_type[m_copacity]}
{
    for(int i = 0; auto& val : list)
    {
        m_arr[i] = val;
        ++i;
    }    
}
template <typename value_type>
Vector<value_type>::~Vector()
{
    clear();
}
template <typename value_type>
size_t Vector<value_type>::size() const
{
    return m_size;
}
template <typename value_type>
size_t Vector<value_type>::copacity() const
{
    return m_copacity;
}
template <typename value_type>
bool Vector<value_type>::empty() const
{
    return !m_size;
}
template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::at(size_type index)
{
    if (index < 0 || index >= m_size)
    {
        throw std::out_of_range("");
    }
    return m_arr[index];
}
template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::at(size_type index) const
{
    if (index < 0 || index >= m_size)
    {
        throw std::out_of_range("");
    }
    return m_arr[index];
}
template <typename value_type>
void Vector<value_type>::push_back(value_type value)
{
    if (m_size == m_copacity)
    {
        resize();
    }
    m_arr[m_size] = value;
    ++m_size;
}
template <typename value_type>
void Vector<value_type>::resize()
{
    m_copacity = m_copacity == 0? 1 : m_copacity *= 2;
    pointer tmp = new value_type[m_copacity];
    for (size_type i = 0; i < m_size; ++i)
    {
        tmp[i] = m_arr[i];
    }
    delete [] m_arr;
    m_arr = tmp;
}
template <typename value_type>
void Vector<value_type>::pop_back()
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
template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::operator[](size_type index) noexcept
{
    return m_arr[index];
}
template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::operator[](size_type index) const noexcept
{
    return m_arr[index];
}
template <typename value_type>
typename Vector<value_type>::pointer Vector<value_type>::data()
{
    return m_arr;
}
template <typename value_type>
typename Vector<value_type>::const_pointer Vector<value_type>::data() const
{
    return m_arr;
}
template <typename value_type>
void Vector<value_type>::clear() noexcept
{
    delete [] m_arr;
    m_size = 0;
    m_copacity = 0;
    m_arr = nullptr;
}
template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::insert(iterator it, value_type value)
{
    if (it < m_arr || it > m_arr + m_size)
    {
        throw std::out_of_range("");
    }
    size_type size = (it - m_arr);
    if (m_size == m_copacity)
    {
        resize();
        it = m_arr + size;
    }
    size_type i = m_size;
    while (it < m_arr + i)
    {
         m_arr[i] = m_arr[i - 1]; 
         --i;
    }
    *it = value;
    ++m_size;
    return it;
}
template<typename value_type>
const Vector<value_type>& Vector<value_type>::operator=(const Vector<value_type>& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    clear();
    m_size = rhs.m_size;
    m_copacity = rhs.m_copacity;
    m_arr = new value_type[m_copacity];
    for (size_type i = 0; i < m_size; ++i)
    {
        m_arr[i] = rhs.m_arr[i];
    }
    return *this;
}
template<typename value_type>
void Vector<value_type>::shrink_to_fit()
{
    m_copacity = m_size;
    pointer tmp = new value_type[m_copacity];
    for (size_type i = 0; i < m_size; ++i)
    {
        tmp[i] = m_arr[i];
    }
    delete [] m_arr;
    m_arr = tmp;
}
template<typename value_type>
typename Vector<value_type>::reference Vector<value_type>::front()
{
    return m_arr[0];
}
template<typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::front() const
{
    return m_arr[0];
}
template<typename value_type>
typename Vector<value_type>::reference Vector<value_type>::back()
{
    return m_arr[m_size - 1];
}
template<typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::back() const
{
    return m_arr[m_size - 1];
}
template<typename value_type>
typename Vector<value_type>::pointer Vector<value_type>::find(const_reference value)
{
    for (size_type i = 0; i < m_size; ++i)
    {
        if (m_arr[i] == value)
        {
            return m_arr + i;
        }
    }
    return m_arr + m_size;
}
template<typename value_type>
void Vector<value_type>::reverse()
{
    if (m_size <= 1)
    {
        return;
    }
    for (size_type i = 0; i < m_size / 2; ++i) {
        swap(m_arr[i], m_arr[m_size - i - 1]);
    }
}
template<typename value_type>
void Vector<value_type>::sort()
{
    if (m_size <= 1)
    {
        return;
    }
    for (size_type i = 0; i < m_size; ++i)
    {
        bool flag = true;
        for (size_type j = 0; j < m_size - 1 - i; ++j)
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
template <typename value_type>
void Vector<value_type>::erase(iterator it)
{
    if (it < m_arr || it > m_arr + m_size - 1)
    {
        throw std::out_of_range("");
    }
    while (it < m_arr + m_size)
    {
        *it = *(it + 1);
        ++it;
    }
    --m_size;
}
template <typename value_type>
void Vector<value_type>::unique()
{
    for (size_type i = 0; i < m_size; ++i)
    {
        for (size_type j = i + 1; j < m_size; ++j)
        {
            if (m_arr[i] == m_arr[j])
            {
                erase(j);
                --j;
            }
        }
    }
}
template<typename value_type>
void Vector<value_type>::erase(iterator it, iterator it1)
{
    if (it < m_arr || it1 > m_arr + m_size || it1 - it > m_size)
    {
        throw std::out_of_range("");
    }
    while (it1 < m_arr + m_size)
    {
        *it = *it1;
        ++it;
        ++it1;
    }
    m_size -= it1 - it;
}
template <typename value_type>
void Vector<value_type>::assign(size_type count, value_type value)
{
    m_size = count;
    m_copacity = m_size;
    delete [] m_arr;
    m_arr = new value_type[m_copacity];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = value;
    }
}
template <typename value_type>
Vector<value_type>::Vector(Vector<value_type>&& rhs)
    :
        m_size{rhs.m_size},
        m_copacity{rhs.m_copacity},
        m_arr{rhs.m_arr}
{
    rhs.m_arr = nullptr;
    rhs.m_size = 0;
    rhs.m_copacity = 0;
}
template <typename value_type>
const Vector<value_type>& Vector<value_type>::operator=(Vector<value_type>&& rhs)
{
    m_size = rhs.m_size;
    m_copacity = rhs.m_copacity;
    delete [] m_arr;
    m_arr = rhs.m_arr;
    rhs.m_arr = nullptr;
    rhs.m_size = 0;
    rhs.m_copacity = 0;
    return *this;
}
template <typename value_type>
Vector<value_type>::Vector(size_type count, value_type value)
    :
        m_size{count},
        m_copacity{m_size},
        m_arr{new value_type[m_copacity]{value}}
{
    
}
template <typename value_type>
typename Vector<value_type>::pointer Vector<value_type>::begin()
{
    return m_arr;
}
template <typename value_type>
typename Vector<value_type>::pointer Vector<value_type>::end()
{
    if (empty()) {
        return nullptr;
    }
    return m_arr + m_size;
}








