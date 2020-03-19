#ifndef _EMPLOYEE_HPP
#define _EMPLOYEE_HPP

class Employee
{
    private:
        char* firstName;
        char* lastName;
        char* position;
    public:
        Employee();
        Employee(const char* firstName,
                 const char* lastName,
                 const char* position
                );
        ~Employee();

        void setFirstName(const char* firstName);
        void setLastName(const char* lastName);
        void setPosition(const char* position);
        const char* getFirstName();
        const char* getLastName();
        const char* getPosition();


};

#endif