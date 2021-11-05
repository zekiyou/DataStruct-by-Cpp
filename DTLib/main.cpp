#include <iostream>
#include "smartpointer.h"
using namespace std;
using namespace DTLib;

int main()
{
    cout << "Hello World!" << endl;

    SmartPointer<int> p1 = new int;

    *p1 = 5;

    SmartPointer<int> p2;

    p2 = p1;

    cout << p1.isNull() << endl;

    cout << p2.isNull() << endl;
    cout << *p2 << endl;

    return 0;
}
