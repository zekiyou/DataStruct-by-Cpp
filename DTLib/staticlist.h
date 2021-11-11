#ifndef STATICLIST_H
#define STATICLIST_H
#include "seqlist.h"

namespace DTLib {
template <typename T, int N>
class StaticList : public SeqList<T> {
protected:
    //StaticList用静态数组来作为存储空间
    T m_sapce[N];
public:
    StaticList();
    int capacity() const;
};

template <typename T, int N>
int StaticList<T,N>::capacity() const {
    return N;
}

template <typename T, int N>
StaticList<T,N>::StaticList() {
    SeqList<T>::m_array = m_sapce;
    SeqList<T>::m_length = 0;
}

}

#endif // STATICLIST_H
