#ifndef SEQLIST_H
#define SEQLIST_H

#include "list.h"
#include "exception.h"
namespace DTLib {
//SeqList 顺序存储的线性表结构
//顺序表的顶级抽象父类
//实现顺序表的公共接口
template <typename T>
class SeqList : public List<T>
{
protected:
    T* m_array;
    int m_length;
public:
    bool insert(int i, const T& e);
    bool insert(const T& e);
    bool remove(int i);
    bool set(int i, const T& e);
    bool get(int i, T& e);
    int length() const;
    void clear();

    //提供数组型的操作
    T& operator [] (int i);
    T operator [] (int i) const;

    //顺序表的空间容量接口 由具体子类实现
    virtual int capacity() const = 0;


};

template <typename T>
// insert思路
// 1.判断插入位置是否合法
// 2.判断顺序表容量是否足够
// 3.移动i位置后面的所有元素
// 4.在i位置插入元素
// 5.长度+1
bool SeqList<T>::insert(int i, const T& e)
{
    bool ret = (i>=0) && (i<=length()) && capacity();

    if (ret) {
        for (int pos = length()-1; pos >= i; pos--) {
            m_array[pos+1] = m_array[pos];
        }

        m_array[i] = e;
        m_length++;
    }

    return ret;
}

template <typename T>
bool SeqList<T>::insert(const T& e)
{
    return insert(m_length,e);
}

template <typename T>
// remove思路
// 1.判断插入位置是否合法
// 3.移动i位置后面的所有元素
// 5.长度-1
bool SeqList<T>::remove(int i)
{
    bool ret = (i>=0) && (i<length());

    if (ret) {
        for (int pos = i; pos < length()-1; pos++) {
            m_array[pos] = m_array[pos+1];
        }

        m_length--;
    }

    return ret;
}

template <typename T>
// set思路
// 1.判断set位置是否合法
// 2.set对应位置元素
bool SeqList<T>::set(int i, const T& e)
{
    bool ret = (i>=0) && (i<length());

    if(ret) {
        m_array[i] = e;
    }

    return ret;
}

template <typename T>
// set思路
// 1.判断get位置是否合法
// 2.get对应位置元素
bool SeqList<T>::get(int i, T& e)
{
    bool ret = (i>=0) && (i<length());

    if(ret) {
        e = m_array[i];
    }

    return ret;
}

template <typename T>
int SeqList<T>::length() const
{
    return m_length;
}

template <typename T>
void SeqList<T>::clear()
{
    m_length = 0;
}


template <typename T>
T& SeqList<T>::operator [] (int i)
{
    bool ret = (i>=0) && (i<length());

    if(ret) {
        return m_array[i];
    } else {
        THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid ...");
    }
}

template <typename T>
T SeqList<T>::operator [] (int i) const{
    return const_cast<SeqList<T>&>(*this)[i];
}

}

#endif // SEQLIST_H
