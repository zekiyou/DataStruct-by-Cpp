#include "exception.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
namespace DTLib {

void Exception::init(const char *message, const char *file, int line)
{
    m_message = strdup(message);

    if (file != nullptr) {
        char sl[16] = {0};
        snprintf(sl, sizeof(sl), "%d", line);
        m_location = static_cast<char*>(malloc(strlen(sl) + strlen(file) +2));

        if (m_location != nullptr) {
            m_location =  strcpy(m_location, file);// 将file的内容 拷贝到m_location所指向的堆空间中
            m_location =  strcat(m_location, ":");
            m_location =  strcat(m_location, sl);
        }

    } else {
        m_location = nullptr;
    }

}

Exception::Exception(const char *message)
{
    init(message, nullptr, 0);
}

Exception::Exception(const char *file, int line)
{
    init(nullptr, file, line);
}

Exception::Exception(const char *message, const char *file, int line)
{
    init(message, file, line);
}

Exception::Exception(const Exception &e)
{
    m_message = strdup(e.message());
    m_location = strdup(e.location());
}

Exception &Exception::operator =(const Exception &e)
{
    if (this != &e) {
        free(m_message);
        free(m_location);
        m_message = strdup(e.message());
        m_location = strdup(e.location());
    }

    return *this;
}

const char *Exception::message() const
{
    return m_message;
}

const char *Exception::location() const
{
    return m_location;
}

Exception::~Exception()
{
    free(m_message);
    free(m_location);
}

ArithmeticException::~ArithmeticException()
{

}

NullPointerException::~NullPointerException()
{

}

IndexOutOfBoundsException::~IndexOutOfBoundsException()
{

}

NoEnoughMemoryException::~NoEnoughMemoryException()
{

}

InvalidParameterException::~InvalidParameterException()
{

}

InvailOperationException::~InvailOperationException()
{

}

}

