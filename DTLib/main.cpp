#include <iostream>

#include "smartpointer.h"
#include "sharepointer.h"

#include "exception.h"
#include "object.h"

#include "staticlist.h"
#include "dynamiclist.h"
#include "staticarray.h"
#include "dynamicarray.h"

#include "linklist.h"

using namespace std;
using namespace DTLib;

class Test
{
public:

};

int main()
{

    SharedPointer<Test> p1 = new Test;
    SharedPointer<Test> p2 = p1;

    cout << (p1==p2) << endl;

    return 0;

}

