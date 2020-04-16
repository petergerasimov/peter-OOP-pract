#include "user.hpp"
#include <iostream>
#include <cstring>

User::User()
{
    firstName = nullptr;
    lastName  = nullptr;
    position  = nullptr;
    status = admin;
}

User::User(const char* firstName,
                   const char* lastName,
                   const char* position,
                   USER_STATUS status = user
                  )                         
{
    setFirstName(firstName);
    setLastName(lastName);
    setPosition(position);
    setStatus(status);
}

User::~User()
{
    delete[] firstName;
    delete[] lastName;
    delete[] position;
    if(password) 
        delete[] password;
}

User& User::operator=(const User& a) {
    if(a.firstName)
        setFirstName(a.firstName);
    if(a.lastName)
        setLastName(a.lastName);
    if(a.position)
        setPosition(a.position);
    if(a.password)
        setPassword(a.password);
    status = a.status;

    return *this;
}

void User::setFirstName(const char* firstName)
{
    if(this->firstName)
        delete[] this->firstName;
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);
}
void User::setLastName(const char* lastName)
{
    if(this->lastName)
        delete[] this->lastName;
    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);
}
void User::setPosition(const char* position)
{
    if(this->position)
        delete[] this->position;
    this->position = new char[strlen(position) + 1];
    strcpy(this->position, position);
}
void User::setStatus(USER_STATUS status)
{
    this->status = status;
}

void User::setPassword(const char* password)
{
    if(this->password)
        delete[] this->password;
    this->password = new char[strlen(password) + 1];
    strcpy(this->password, password);
}

const char* User::getFirstName() const
{
    return firstName;
}
const char* User::getLastName() const
{
    return lastName;
}
const char* User::getPosition() const
{
    return position;
}
const USER_STATUS User::getStatus() const
{
    return status;
}

bool User::authenticate(const char* password)
{
    if(!this->password) return true;
    return strcmp(this->password, password) == 0;
}

void User::printInfo() const
{
    std::cout << firstName << " " << lastName << " "
              << position;
}