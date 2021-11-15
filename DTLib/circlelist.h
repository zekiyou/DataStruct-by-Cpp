#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include "linklist.h"
namespace DTLib {

template <typename T>
// 循环列表的实现要点
// 1. 末尾节点的next指针不是nullptr 而是首节点
// 2. 由于需要维护头节点的指向
// 3. 在remove和insert 0位置时需要重新绑定尾节点
// 4. 由于尾节点不指向nullptr while(p)的遍历和clear需要重写
class CircleList : public LinkList<T>
{
protected:

    typename LinkList<T>::Node* last() const
    {
       typename LinkList<T>::Node* ret = reinterpret_cast<typename LinkList<T>::Node*>(&(this->m_header));


        for (int var = 0; var < this->m_length; ++var) {
            ret = ret->next;
        }

        return ret;
    }


    void last_to_first() const
    {
        last()->next = this->m_header.next;
    }


public:
    virtual bool insert(int i, const T& e) override;
    virtual bool insert(const T& e) override;

    virtual bool remove(int i) override;
    virtual void clear() override;

    ~CircleList();
};

template <typename T>
bool CircleList<T>::insert(const T& e)
{
    return insert(this->m_length,e);
}

template <typename T>
bool CircleList<T>::insert(int i, const T& e)
{
    bool ret = false;

    i = i % (this->m_length + 1);

    ret = LinkList<T>::insert(i,e);

    if (ret && (i==0))
    {
        last_to_first();
    }


    return ret;

}

template <typename T>
bool CircleList<T>::remove(int i)
{
    bool ret = false;

    i = i % (this->m_length + 1);

    ret = LinkList<T>::remove(i);


    if (ret && (i==0) && this->length() > 0)
    {

        last_to_first();

    } else if (this->length() <=0 ){


        this->m_header.next = nullptr;
        this->m_cur = nullptr;
    }

    return ret;
}

template<typename T>
void CircleList<T>::clear()
{
    while( this->m_length > 1 )  // O(n)
    {
        remove(1);   // O(1)，这里没有调用 remove(0) 是因为避免大量移动指针，提高效率；
    }

    if( this->m_length == 1 )     // O(1)
    {
        typename LinkList<T>::Node*  toDel = this->m_header.next;
        this->m_header.next = NULL;
        this->m_cur = NULL;
        this->m_length = 0;
        this->destory(toDel );
    }
}

template<typename T>
CircleList<T>::~CircleList()
{
    clear();
}




}

#endif // CIRCLELIST_H
