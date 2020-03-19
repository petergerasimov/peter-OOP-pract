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

    public:
        HomeOffice();
        HomeOffice(int size);
        ~HomeOffice();
        void add(const Employee &employee);
        void remove(const char* name);
        void list();

};

#endif