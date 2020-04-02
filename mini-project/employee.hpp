#ifndef _EMPLOYEE_HPP
#define _EMPLOYEE_HPP

enum EMPLOYEE_STATUS {admin, user};

class Employee
{
    private:
        char* firstName;
        char* lastName;
        char* position;
        char* password = nullptr;
        EMPLOYEE_STATUS status;
    public:
        Employee();
        Employee(const char* firstName,
                 const char* lastName,
                 const char* position,
                 EMPLOYEE_STATUS status
                );
        ~Employee();


        //Setters
        void setFirstName(const char* firstName);
        void setLastName(const char* lastName);
        void setPosition(const char* position);
        void setStatus(EMPLOYEE_STATUS status);
        void setPassword(const char* password);

        //Getters
        const char* getFirstName();
        const char* getLastName();
        const char* getPosition();
        EMPLOYEE_STATUS getStatus();
        bool authenticate(const char* password);



};

#endif