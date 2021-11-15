#ifndef SHAREPOINTER_H
#define SHAREPOINTER_H

#include "pointer.h"
#include "exception.h"

namespace DTLib {

//SharedPointer 智能指针
// 通过计数机制（ref）标识堆空间；
// 堆内存被指向时：ref++；
// 指针被置空时：ref--；
// ref == 0 时：释放堆内存；

template <typename T>
class SharedPointer : public Pointer<T>
{
protected:
    int* m_ref;
public:
    SharedPointer(T* p = nullptr);
    SharedPointer(const SharedPointer<T>& obj);
    SharedPointer<T>& operator = (const SharedPointer<T>& obj);
    ~SharedPointer();

    void clear();


};

template<typename T>
SharedPointer<T>::SharedPointer(T *p)
{
    m_ref = nullptr;

    if (p) {

        m_ref = new int;

        if (m_ref) {
            *(this->m_ref) = 1;
            this->m_pointer = p;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "NoEnoughMemoryException");
        }

    }

}

template<typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &obj)
{
    this->m_pointer = obj.m_pointer;
    this->m_ref = obj.m_ref;

    if (m_ref) {
        *m_ref ++;
    }

}

template<typename T>
SharedPointer<T>& SharedPointer<T>::operator =(const SharedPointer<T> &obj)
{
    if (obj != *this) {
        clear();

        this->m_pointer = obj.m_pointer;
        this->m_ref = obj.m_ref;

        if (m_ref) {
            *m_ref ++;
        }

    }

    return *this;
}

template<typename T>
SharedPointer<T>::~SharedPointer()
{
    clear();
}

template<typename T>
void SharedPointer<T>::clear()
{
    T* toDel = this->m_pointer;
    int* ref = this->m_ref;

    this->m_ref = nullptr;
    this->m_pointer = nullptr;

    if (ref) {
        (*ref) -- ;
        if (*ref == 0) {

            delete ref;
            delete toDel;

        }
    }

}

template<typename T>
bool operator == (const SharedPointer<T>& obj1, const SharedPointer<T>& obj2)
{
    return (obj1.get() == obj2.get());
}

template<typename T>
bool operator != (const SharedPointer<T>& obj1, const SharedPointer<T>& obj2)
{
    return !(obj1 == obj2);
}

}

#endif // SHAREPOINTER_H
