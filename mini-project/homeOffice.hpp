#ifndef _HOME_OFFICE_HPP
#define _HOME_OFFICE_HPP

#include "employee.hpp"

class HomeOffice
{
    private:
        Employee* employees;
        int size;
        int top;
        bool full();
        bool empty();
        void resize();
        
        void remove(const char* name);

    public:
        HomeOffice();
        HomeOffice(int size);
        ~HomeOffice();
        void add(const Employee &employee); //this should be private but for testing it isn't
        void addBy(Employee &contributor, const Employee &toBeAdded, const char* password = " ");
        void removeBy(Employee &contributor, const char* toBeRemoved, const char* password = " ");
        void list();

};

#endif