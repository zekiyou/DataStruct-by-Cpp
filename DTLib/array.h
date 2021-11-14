#ifndef ARRAY_H
#define ARRAY_H

#include "object.h"
#include "exception.h"

namespace DTLib {
// Array的顶级抽象父类
// 原生数组的缺陷
// 1. 无法获取长度信息
// 2. 数组越界访问没有异常
template <typename T>
class Array : public Object
{
protected:
    T* m_array;
public:
    virtual bool set(int i, const T& e)
    {
        bool ret = ((0<=i) && (i< length()));

        if (ret) {
            m_array[i] = e;
        }

        return ret;

    }

    virtual bool get(int i,  T& e)
    {
        bool ret = ((0<=i) && (i< length()));

        if (ret) {
            e = m_array[i];
        }

        return ret;

    }

    T& operator [] (int i)
    {
        if ((0<=i) && (i< length())) {
            return m_array[i];
        } else {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Out of index");
        }
    }

    T& operator [] (int i) const
    {
        return const_cast<Array<T>&>(this->operator[](i));
    }

    virtual int length() const = 0;

};
}

#endif // ARRAY_H
