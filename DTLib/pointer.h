#ifndef POINTER_H
#define POINTER_H
#include "object.h"

namespace DTLib{
template <typename T>
// 智能指针的抽象顶级父类   Pointer
// 提供指针所需的接口
class Pointer : public Object
{
protected:
    T* m_pointer;
public:
    Pointer(T* p = nullptr) {
        m_pointer = p;
    }

    T* operator -> (){
        return m_pointer;
    }

    T* operator * () {
        return *m_pointer;
    }

    const T* operator -> () const{
        return m_pointer;
    }

    const T* operator * ()  const{
        return *m_pointer;
    }


    bool isNull() {
        return  m_pointer == nullptr;
    }

    const T* get() const{
        return m_pointer;
    }

};
}

#endif // POINTER_H
