#include <iostream>
#include "smartpointer.h"
#include "exception.h"

using namespace std;
using namespace DTLib;

int main()
{
    try {
      cout << __FILE__ << ":" << __LINE__ << endl;
      THROW_EXCEPTION(ArithmeticException, "my Arithmeticexception");
    }

    catch (const ArithmeticException& e) {
        cout << "ArithmeticException" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    catch (const Exception& e) {
        cout << "Exception" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}
