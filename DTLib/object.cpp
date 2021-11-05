#include "object.h"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace DTLib
{
/* 这个重载函数针对单个对象， throw() 是异常规格说明，函数不会抛出任何异常 */
void* Object::operator new (size_t size) throw()
{
    cout << "void* Object::operator new " << size << endl;
    return malloc(size);
}

/*  */
void Object::operator delete(void* p)
{
    cout << "void Object::operator delete"<< p << endl;
    free(p);
}

/*  */
void* Object::operator new[] (size_t size) throw()
{
    return malloc(size);
}

/*  */
void Object::operator delete[] (void* p)
{
    free(p);
}

bool Object::operator == (const Object& obj)
{
    return (this == &obj);
}

bool Object::operator != (const Object& obj)
{
    return (this != &obj);
}

/*  */
Object::~Object()
{

}

}


