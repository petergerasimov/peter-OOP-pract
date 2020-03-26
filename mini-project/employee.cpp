#include "employee.hpp"
#include <iostream>
#include <cstring>

Employee::Employee()
{
    firstName = nullptr;
    lastName  = nullptr;
    position  = nullptr;
}

Employee::Employee(const char* firstName,
                   const char* lastName,
                   const char* position
                  )                         
{
    //maybe make a function for this so it doesn't repeat 1000 times
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);

    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);

    this->position = new char[strlen(position) + 1];
    strcpy(this->position, position);
}

Employee::~Employee()
{
    delete[] firstName;
    delete[] lastName;
    delete[] position;
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
