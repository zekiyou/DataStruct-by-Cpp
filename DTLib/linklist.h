#ifndef LINKLIST_H
#define LINKLIST_H

#include "list.h"
#include "object.h"
#include "exception.h"

namespace DTLib{

template  <typename T>
class LinkList : public List<T>
{
protected:

    struct Node
    {
        T value;
        Node* next;
    };

    mutable struct {
        char reserved[sizeof(T)];
        Node* next;
    }m_header;

    int m_length;
    int m_step;
    Node* m_cur;

public:
    LinkList();
    ~LinkList();

    virtual bool insert(int i, const T& e);
    virtual bool insert(const T& e);
    virtual bool remove(int i);
    virtual bool get(int i, T& e);
    virtual T get(int i);
    virtual bool set(int i, const T& e);
    virtual void clear();
    virtual int length() const;
    virtual int find(const T& e) const;

    virtual bool move(int i, int step=1);
    virtual bool end();
    virtual T current();
    virtual bool next();

    virtual Node* creat();
    virtual void destory(Node* p);

};

template  <typename T>
LinkList<T>::LinkList()
{
    m_header.next = nullptr;
    m_length = 0;
}

template  <typename T>
bool LinkList<T>::insert(const T& e)
{
    return insert(m_length, e);
}

template  <typename T>
//链表插入要点
//1.NEW新的结点存储数据
//2.循环列表指向所插入的前一个位置
//3.断开 插入
//4.长度+1
bool LinkList<T>::insert(int i, const T& e)
{
    bool ret = ((i>=0) && (i<=m_length));

    if (ret) {

        Node* node = creat();

        if (node != nullptr) {

            Node* current = reinterpret_cast<Node*>(&m_header);

            for (int var = 0; var < i; ++var) {
                current = current->next;
            }

            node->next = current->next;
            node->value = e;
            current->next = node;

            m_length++;

        }
    } else {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to resize");
    }

    return ret;
}

template  <typename T>
//删除插入要点
//1.循环列表指向所删除的前一个位置
//2.断开 删除
//3.长度-1
bool LinkList<T>::remove(int i)
{

    bool ret = ((i>=0) && (i<=m_length));

    if (ret) {
         Node* current = reinterpret_cast<Node*>(&m_header);
        for (int var = 0; var < i; ++var) {
            current = current->next;
        }

        Node* node = current->next;
        current->next = node->next;

        m_length--;
        destory(node);

    }

    return ret;
}

template  <typename T>
//set要点
//1.循环列表指向所删除的前一个位置
//2.设置下一个目标的值
bool LinkList<T>::set(int i, const T& e)
{
    bool ret = ((i>=0) && (i<=m_length));

    if (ret) {
        Node* current = reinterpret_cast<Node*>(&m_header);
        for (int var = 0; var < i; ++var) {
            current = current->next;
        }

        current->next->value = e;

    }
    return ret;
}

template  <typename T>
//get要点
//1.循环列表指向所删除的前一个位置
//2.取下一个目标的值
bool LinkList<T>::get(int i, T& e)
{
    bool ret = ((i>=0) && (i<=m_length));

    if (ret) {
        Node* current = reinterpret_cast<Node*>(&m_header);
        for (int var = 0; var < i; ++var) {
            current = current->next;
        }

        e = current->next->value;

    }

    return ret;
}

template  <typename T>
T LinkList<T>::get(int i)
{
    T ret;

    if (get(i ,ret)) {

    } else {
        THROW_EXCEPTION(IndexOutOfBoundsException, "IndexOutOfBoundsException");
    }

    return ret;
}

template  <typename T>
int LinkList<T>::length() const
{
    return m_length;
}

template  <typename T>
void LinkList<T>::clear()
{

    m_length = 0;

    while (m_header.next) {
        Node* node = m_header.next;
        m_header.next = node->next;

        destory(node);
    }


}


template  <typename T>
LinkList<T>::~LinkList()
{
    clear();
}

template  <typename T>
int LinkList<T>::find(const T& e) const
{
    int ret = -1;

    Node* current = reinterpret_cast<Node*>(&m_header);
    for (int var = 0; var < m_length; ++var) {

        if (current->value == e) {
            ret = var;
            break;
        }

        current = current->next;
    }

    return ret;
}

template <typename T>
bool LinkList<T>::move(int i, int step)
{
    bool ret = (0<=i) && (i<m_length) && (step > 0);

    if (ret) {

        Node* current = reinterpret_cast<Node*>(&m_header);

        for (int var = 0; var < i; ++var) {
            current = current->next;
        }

        m_cur = current->next;

        m_step = step;
    }

    return ret;
}

template <typename T>
bool LinkList<T>::end()
{
    return m_cur == nullptr;
}

template <typename T>
T LinkList<T>::current()
{
    T ret;

    if (!end())
        ret = m_cur->value;
    else {
        THROW_EXCEPTION(IndexOutOfBoundsException, "IndexOutOfBoundsException");
    }
    return ret;
}


template <typename T>
bool LinkList<T>::next()
{
    int i = 0;

    while (i < m_step && !end()) {
        m_cur = m_cur->next;
        i++;
    }

    return (i==m_step);

}

template<typename T>
typename LinkList<T>::Node* LinkList<T>::creat()
{
    return new Node;
}

template<typename T>
void LinkList<T>::destory(Node* p)
{
    delete p;
}

}

#endif // LINKLIST_H
