#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#include "linklist.h"

namespace DTLib {

template <typename T, int N>
class StaticList : public LinkList<T>
{
protected:
    unsigned char m_space[N*sizeof(LinkList<T>::Node)];
    int m_used[N];

    struct SNode : public LinkList<T>::Node
    {
        void * operator new (size_t size, void* loc)
        {
            (void)size;
            return loc;
        }

    };

public:
    virtual typename LinkList<T>::Node* creat();
    virtual void destory(typename LinkList<T>::Node* p);
    StaticList();
    ~StaticList();
    int capacity();

};

template <typename T, int N>
StaticList<T,N>::StaticList()
{
    for (int i=0; i<N; i++) {
        m_used[i] = 0;
    }
}

template<typename T, int N>
StaticList<T,N>::~StaticList()
{
    this->clear();
}

template <typename T, int N>
typename LinkList<T>::Node* StaticList<T, N>::creat()
{
    SNode* ret = nullptr;

    for (int i=0; i<N; i++) {
        if (!m_used[i]) {
            ret = reinterpret_cast<SNode*>(m_space) + i;
            ret = new(ret)SNode();
            m_used[i] = 1;
            break;
        }
    }

}

template <typename T, int N>
void StaticList<T, N>::destory(typename LinkList<T>::Node* p)
{
    SNode* ret = reinterpret_cast<SNode*>(m_space);
    SNode* psn = reinterpret_cast<SNode*>(p);

    for (int i=0; i<N; i++) {
        if ( psn == (ret + 1)) {
            m_used[i] = 0;
            delete psn;
            break;
        }
    }

}

template<typename T, int N>
int StaticList<T,N>::capacity()
{
    return N;
}

}

#endif // STATICLINKLIST_H
