#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
using namespace std;
namespace DTLib
{
class Object
{
  public:
    void* operator new (size_t size, nothrow_t&) noexcept;
    void operator delete(void* p);
    void* operator new[] (size_t size, nothrow_t&) noexcept;
    void operator delete[](void* p);
    bool operator == (const Object& obj);
    bool operator != (const Object& obj);
    virtual ~Object() = 0;/* 为什么将析构函数定义为纯虚函数？*/
                          /* 使得顶级父类是一个抽象类，也可以保证这个类的所有子类当中都有虚函数表的指针了，也就可以使用动态类型识别相关的技术；*/
};
}
#endif // OBJECT_H
