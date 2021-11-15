#include <iostream>

#include "smartpointer.h"
#include "sharepointer.h"

#include "exception.h"
#include "object.h"

#include "staticlist.h"
#include "dynamiclist.h"
#include "circlelist.h"
#include "staticarray.h"
#include "dynamicarray.h"

#include "linklist.h"

using namespace std;
using namespace DTLib;

class Test
{
public:

};

void josephus(int n, int k, int m)
{
    CircleList<int> c1;

    for (int var = 1; var <= n; ++var) {
        c1.insert(var);
    }

    cout << "============================" << endl;

    c1.move(k-1, m-1);

    cout << "============================" << endl;

    for (int var = 0; var < c1.length(); ++var) {
        cout << c1.get(var) << endl;
    }

    cout << "============================" << endl;

    cout << c1.current() << endl;

    cout << c1.end() << endl;

    cout << "============================" << endl;

    cout << c1.end() << endl;

    cout << "============================" << endl;

    while (c1.length() > 0) {
       c1.next();

       cout << c1.current() << endl;

       c1.remove(c1.find(c1.current()));
    }

    cout << "============================" << endl;

}

int main()
{

    josephus(41, 1, 3);

    return 0;

}

