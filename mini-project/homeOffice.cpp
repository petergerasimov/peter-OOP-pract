#include "homeOffice.hpp"
#include <iostream>
#include <cstring>

const int INIT_SIZE = 16;
const int EMPTY = -1;

HomeOffice::HomeOffice()
{
    employees = new Employee[INIT_SIZE];
    this->size = size;
    top = EMPTY;
}

HomeOffice::HomeOffice(int size)
{
    employees = new Employee[size];
    this->size = size;
    top = EMPTY;
}

HomeOffice::~HomeOffice()
{
    //TODO
}

bool HomeOffice::full() {return top == size - 1;}
bool HomeOffice::empty() {return top == EMPTY;}
void HomeOffice::resize()
{
    int newSize = size * 2;
    Employee* newEmployees = new Employee[newSize];

    for(int i = 0; i < size; i++)
        newEmployees[i] = employees[i];
    
    size = newSize;
    delete[] employees;
    employees = newEmployees;
}

void HomeOffice::add(const Employee &employee)
{
    if(full())
        resize();
    
    employees[++top] = employee;
}

void HomeOffice::addBy(Employee &contributor, const Employee &toBeAdded, const char* password)
{
    if(contributor.getStatus() == admin && contributor.authenticate(password))
        add(toBeAdded);
}

//Remove by fist name (TODO remove by id)
void HomeOffice::remove(const char* name)
{
    if(empty())
        return;
    
    for(int i = 0; i <= top; i++)
    {
        if(strcmp(name,employees[i].getFirstName()) == 0)
        {
            employees[i] = employees[top--];
            return;
        }
    } 
}

void HomeOffice::removeBy(Employee &contributor, const char* toBeRemoved, const char* password)
{
    if(contributor.getStatus() == admin && contributor.authenticate(password))
        remove(toBeRemoved);
}

void HomeOffice::list()
{
    for(int i = 0; i <= top; i++)
    {
        std::cout << i << ": " 
                  << employees[i].getFirstName() << " " 
                  << employees[i].getLastName()  << " " 
                  << employees[i].getPosition()  << std::endl;
    }
}