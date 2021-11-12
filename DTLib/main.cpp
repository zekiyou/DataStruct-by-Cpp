#include <iostream>

#include "smartpointer.h"
#include "exception.h"
#include "object.h"
#include "staticlist.h"
#include "dynamiclist.h"
#include "staticarray.h"
#include "dynamicarray.h"

using namespace std;
using namespace DTLib;

int main()
{
    DynamicArray<int> s1(10);

    for (int i=0; i<s1.length(); i++) {
        s1[i] = i;
    }

    cout << s1.length() << endl;

    s1.resize(15);

    for (int i=0; i<s1.length(); i++) {
        cout << s1[i] << endl;
    }

    return 0;
}

