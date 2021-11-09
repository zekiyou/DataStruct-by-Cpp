#include <iostream>
#include "smartpointer.h"
#include "exception.h"
#include "object.h"

using namespace std;
using namespace DTLib;

int main()
{
    try{
        throw NullPointerException("This is my Exception tet",  __FILE__, __LINE__);
    } catch (const Exception& e) {
        cout << e.message() ;
    }
    return 0;
}
