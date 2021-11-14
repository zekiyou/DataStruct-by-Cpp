#ifndef STATICARRAY_H
#define STATICARRAY_H
#include "array.h"
namespace DTLib {
template <typename T, int N>
//静态数组
//在堆上创建空间完成Array功能
class StaticArray : public Array<T>
{
protected:
    T m_space[N];
public:
    StaticArray();
    StaticArray(const StaticArray<T,N>& obj);
    StaticArray<T,N>& operator = (const StaticArray<T,N>& obj);
    int length() const;
};

template <typename T, int N>
StaticArray<T,N>::StaticArray()
{
    Array<T>::m_array = m_space;
}

template <typename T, int N>
StaticArray<T,N>::StaticArray(const StaticArray<T,N>& obj)
{
    Array<T>::m_array = m_space;
    for (int i=0; i<N; i++) {
        m_space[i] = obj.m_space[i];
    }
}

template <typename T, int N>
int StaticArray<T,N>::length() const
{
    return N;
}

template <typename T, int N>
StaticArray<T,N>& StaticArray<T,N>::operator = (const StaticArray<T,N>& obj)
{
    if (this != &obj) {
        for (int i=0; i<N; i++) {
            m_space[i] = obj.m_space[i];
        }
    }
    return *this;
}


}
#endif // STATICARRAY_H
