#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include <iostream>
#include "pointer.h"
using namespace std;
namespace DTLib {
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
