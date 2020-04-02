#include "employee.hpp"
#include <iostream>
#include <cstring>

Employee::Employee()
{
    firstName = nullptr;
    lastName  = nullptr;
    position  = nullptr;
    status = user;
}

Employee::Employee(const char* firstName,
                   const char* lastName,
                   const char* position,
                   EMPLOYEE_STATUS status = user
                  )                         
{
    //maybe make a function for this so it doesn't repeat 1000 times
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);

    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);

    this->position = new char[strlen(position) + 1];
    strcpy(this->position, position);

    this->status = status;
}

Employee::~Employee()
{
    delete[] firstName;
    delete[] lastName;
    delete[] position;
    if(password) 
        delete[] password;
}

void Employee::setFirstName(const char* firstName)
{
    if(this->firstName)
        delete[] this->firstName;
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);
}
void Employee::setLastName(const char* lastName)
{
    if(this->lastName)
        delete[] this->lastName;
    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);
}
void Employee::setPosition(const char* position)
{
    if(this->position)
        delete[] this->position;
    this->position = new char[strlen(position) + 1];
    strcpy(this->position, position);
}
void Employee::setStatus(EMPLOYEE_STATUS status)
{
    this->status = status;
}

void Employee::setPassword(const char* password)
{
    if(this->password)
        delete[] this->password;
    this->password = new char[strlen(password) + 1];
    strcpy(this->password, password);
}

const char* Employee::getFirstName()
{
    return firstName;
}
const char* Employee::getLastName()
{
    return lastName;
}
const char* Employee::getPosition()
{
    return position;
}
EMPLOYEE_STATUS Employee::getStatus()
{
    return status;
}

bool Employee::authenticate(const char* password)
{
    if(!this->password) return true;
    return strcmp(this->password, password) == 0;
}