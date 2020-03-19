#include <iostream>
#include "employee.hpp"


int main()
{
    Employee gosho("Gosho","Petrov","CEO");
    std::cout << gosho.getFirstName();
    return EXIT_SUCCESS;
}