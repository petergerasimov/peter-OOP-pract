#include <iostream>
#include "employee.hpp"
#include "homeOffice.hpp"

int main()
{
    homeOffice office;
    Employee gosho("Gosho","Petrov","CEO");
    Employee pesho("Pesho","Petrov","CEO");
    Employee tisho("Tisho","Petrov","CEO");
    office.add(gosho);
    office.list();
    std::cout << "--------------\n";
    office.add(pesho);
    office.add(tisho);
    office.list();
    std::cout << "--------------\n";
    office.remove("Gosho");
    office.list();
    std::cout << "--------------\n";
    return EXIT_SUCCESS;
}