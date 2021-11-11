#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H
#include "seqlist.h"
namespace DTLib {
template <typename T>
class DynamicList : public SeqList<T>
{
private:
    //DynamicList的容量是可变的
    int m_capacity;
public:
    DynamicList(int capacity);
    int capacity() const override;
    void resize(int capacity);
    ~DynamicList();
};

template <typename T>
DynamicList<T>::DynamicList(int capacity) {
    SeqList<T>::m_array = new T[capacity];

    if (SeqList<T>::m_array != nullptr) {
        SeqList<T>::m_length = 0;
        m_capacity = capacity;
    }

}

template <typename T>
int DynamicList<T>::capacity() const {
    return m_capacity;
}

template <typename T>
//resize要点
//1. 判断是否需要扩容/减容量
//2. 申请新一片空间
//3. 移动元素值
//4. 更改指向空间，释放原空间
//5. 更新长度，容量
void DynamicList<T>::resize(int capacity) {
    if (capacity == m_capacity)
        return;
    else {
        T* array = new T[capacity];

        if (array != nullptr) {
            // 通过比较原表和capcaity来决定需要复制的元素的个数
            int length = ((SeqList<T>::m_length) < capacity ? (SeqList<T>::m_length) : capacity );

            for (int i=0; i<length; i++) {
                array[i] = SeqList<T>::m_array[i];
            }

            T* temp = SeqList<T>::m_array;
            SeqList<T>::m_length = length;
            SeqList<T>::m_array = array;
            m_capacity = capacity;
            delete []  temp;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to resize");
        }

    }
}


template <typename T>
DynamicList<T>::~DynamicList() {
    delete [] SeqList<T>::m_array;
}

}
#endif // DYNAMICLIST_H
