#ifndef _HOME_OFFICE_HPP
#define _HOME_OFFICE_HPP

#include "employee.hpp"

class homeOffice
{
    private:
        Employee* employees;
        int size;
        int top;
        bool full();
        bool empty();
        void resize();

    public:
        homeOffice();
        homeOffice(int size);
        void add(const Employee &employee);
        void remove(const char* name);
        void list();

};

#endif