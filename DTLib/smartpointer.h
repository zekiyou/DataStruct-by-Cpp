#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include <iostream>
#include "pointer.h"
using namespace std;
namespace DTLib {
//SmartPointer 智能指针
// 1，指针生命周期结束时主动释放堆空间；
// 2，一片堆空间最多只能由一个指针标识；
// 3, 杜绝指针之间的运算
template <typename T>
class SmartPointer : public Pointer<T>
{
public:
    SmartPointer(T* p = nullptr) : Pointer<T>(p)
    {

    }


    ~SmartPointer()
    {
        delete this->m_pointer;
    }

    SmartPointer(const SmartPointer<T>& obj)
    {
        cout << "SmartPointer(const SmartPointer<T>& obj)" << endl;
        this->m_pointer = obj.m_pointer;
        const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
    }

    SmartPointer<T>& operator = (const SmartPointer<T>& obj)
    {
        cout << "SmartPointer<T>& operator = (const SmartPointer<T>& obj)" << endl;
        if (&obj != this) {

            delete this->m_pointer;
            this->m_pointer = obj.m_pointer;
            const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;

        }
    }



};

}
#endif // SMARTPOINTER_H
