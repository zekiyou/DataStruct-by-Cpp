#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include <iostream>
#include "object.h"
using namespace std;
namespace DTLib {
template <typename T>
class SmartPointer : public Object
{
protected:
    T* m_pointer = nullptr;
public:
    SmartPointer(T* p = nullptr)
    {
        cout << "SmartPointer(T* p = nullptr)" << endl;
        m_pointer = p;
    }

    T* operator -> ()
    {
        return m_pointer;
    }

    T& operator * ()
    {
        return *m_pointer;
    }

    bool isNull()
    {
        return (m_pointer == nullptr);
    }

    T* get()
    {
        return m_pointer;
    }

    ~SmartPointer()
    {
        delete m_pointer;
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
            delete m_pointer;
            this->m_pointer = obj.m_pointer;
            const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
        }
    }

};

}
#endif // SMARTPOINTER_H
