#include <iostream>

#include "smartpointer.h"
#include "exception.h"
#include "object.h"

#include "staticlist.h"
#include "dynamiclist.h"
#include "staticarray.h"
#include "dynamicarray.h"

#include "linklist.h"

using namespace std;
using namespace DTLib;

class Test : public Object
{
public:

};

int main()
{
    LinkList<int> s1;

    for (int var = 0; var < 10; ++var) {
        s1.insert(var);
    }

    for (int var = 0; var < s1.length(); ++var) {
        cout << s1.get(var) << endl;
    }

    s1.remove(2);

    cout << "================================" << endl;

    for (int var = 0; var < s1.length(); ++var) {
        cout << s1.get(var) << endl;
    }

    cout << "================================" << endl;

    cout << s1.find(4) << endl;

    cout << "================================" << endl;

    for (s1.move(0); !(s1.end()); s1.next()) {
        cout << s1.current() << endl;
    }

    cout << "================================" << endl;

    return 0;

}

