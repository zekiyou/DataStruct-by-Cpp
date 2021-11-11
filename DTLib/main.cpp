#include <iostream>
#include "smartpointer.h"
#include "exception.h"
#include "object.h"
#include "staticlist.h"
#include "dynamiclist.h"
using namespace std;
using namespace DTLib;

int main()
{
    DynamicList<int> s1(10);

    cout << s1.length() << endl;

    for (int i=0; i<s1.capacity(); i++) {
        s1.insert(0,i);
    }

    cout << s1.length() << endl;

    for (int i=0; i<s1.length(); i++) {
        cout << s1[i] << endl;
    }
    cout << "======================" << endl;

    try {
        s1[10] = 5;
    } catch (Exception& e) {
        cout << e.message() << endl;
        s1.resize(15);
    }

    cout << "======================" << endl;
    cout << s1.length() << endl;

    for (int i=0; i<s1.length(); i++) {
        cout << s1[i] << endl;
    }

    return 0;
}

