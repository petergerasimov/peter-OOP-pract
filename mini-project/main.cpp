#include <iostream>
#include "employee.hpp"
#include "homeOffice.hpp"
#include "date.hpp"

int main()
{
    Employee gosho("Gosho", "Goshev", "shef", admin);
    Employee tosho("Tosho", "Toshev", "ne shef", user);
    gosho.setPassword("123");

    HomeOffice office;
    office.add(gosho); //maybe initialize class with a default admin account
    office.addBy(gosho, tosho, "124");
    std::cout << "-------------\n";
    office.list();
    std::cout << "-------------\n";
    office.addBy(gosho, tosho, "123");
    office.list();
    std::cout << "-------------\n";
    office.removeBy(tosho, "Gosho");
    office.list();
    std::cout << "-------------\n";
    office.removeBy(gosho, "Tosho", "123");
    office.list();
    std::cout << "-------------\n";

    return EXIT_SUCCESS;
}