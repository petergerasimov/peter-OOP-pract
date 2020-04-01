#include <iostream>
#include "employee.hpp"
#include "homeOffice.hpp"
#include "date.hpp"

int main()
{
    Date test(5,16,2002);
    //Date test1(1,2,9);
    //Date test2 = test + test1;
    test.print();

    return EXIT_SUCCESS;
}