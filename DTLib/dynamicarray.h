#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include "array.h"
#include "exception.h"
namespace DTLib {
template <typename T>
class DynamicArray : public Array<T>
{
protected:
    int m_length;
public:
    DynamicArray (int length)
    {
        Array<T>::m_array = new T[length];

        if (Array<T>::m_array != nullptr) {
            m_length = length;
        }

    }

    DynamicArray (const DynamicArray<T>& obj)
    {
        Array<T>::m_array = new T[obj.m_length];

        if (Array<T>::m_array != nullptr) {
            m_length = obj.m_length;

            for (int var = 0; var < m_length; ++var) {
                Array<T>::m_array[var] = obj.m_array[var];
            }

        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "NoEnoughMemoryException");
        }
    }

    const DynamicArray& operator = (const DynamicArray<T>& obj)
    {
        if (obj != *this) {

            T* array = new T[obj.m_length];

            if (array != nullptr) {
                m_length = obj.m_length;

                for (int var = 0; var < m_length; ++var) {
                    array[var] = obj.m_array[var];
                }

                T* tmp = Array<T>::m_array;
                Array<T>::m_array = array;

                delete [] tmp;

            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "NoEnoughMemoryException");
            }
        }
    }


    int length () const
    {
        return m_length;
    }

    void resize(int length)
    {
        if (length != m_length) {

            T* array = new T[length];

            int i = (length < m_length)? length : m_length;

            for (int var = 0; var < i; ++var) {
                array[var] = Array<T>::m_array[var];
            }

            T* tmp = Array<T>::m_array;
            Array<T>::m_array = array;
            m_length = length;

            delete [] tmp;

        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "NoEnoughMemoryException");
        }
    }

};
}

#endif // DYNAMICARRAY_H
