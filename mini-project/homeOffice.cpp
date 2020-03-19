#include "homeOffice.hpp"
#include <iostream>
#include <cstring>

const int INIT_SIZE = 16;
const int EMPTY = -1;

homeOffice::homeOffice()
{
    employees = new Employee[INIT_SIZE];
    this->size = size;
    top = EMPTY;
}

homeOffice::homeOffice(int size)
{
    employees = new Employee[size];
    this->size = size;
    top = EMPTY;
}

bool homeOffice::full() {return top == size - 1;}
bool homeOffice::empty() {return top == EMPTY;}
void homeOffice::resize()
{
    int newSize = size * 2;
    Employee* newEmployees = new Employee[newSize];

    for(int i = 0; i < size; i++)
        newEmployees[i] = employees[i];
    
    size = newSize;
    delete[] employees;
    employees = newEmployees;
}

void homeOffice::add(const Employee &employee)
{
    if(full())
        resize();
    
    employees[++top] = employee;
}

//Remove by fist name (TODO remove by id)
void homeOffice::remove(const char* name)
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

void homeOffice::list()
{
    for(int i = 0; i <= top; i++)
    {
        std::cout << i << ": " 
                  << employees[i].getFirstName() << " " 
                  << employees[i].getLastName()  << " " 
                  << employees[i].getPosition()  << std::endl;
    }
}