#ifndef LIST_H
#define LIST_H
#include "object.h"
namespace DTLib {
//链表的顶层抽象父类
// 提供链表所需基本功能接口
template <typename T>
    class List : public Object {
    protected:
        //禁用列表的赋值和拷贝构造  避免重复释放内存
        List(const List&);
        List& operator = (const List&);
    public:
        List() {}
        virtual bool insert(int i, const T& e) = 0;
        virtual bool insert(const T& e) = 0;
        virtual bool remove(int i) = 0;
        virtual bool set(int i, const T& e) = 0;
        virtual bool get(int i, T& e) = 0;
        virtual int length() const = 0;
        virtual void clear() = 0;
    };

}
#endif // LIST_H
