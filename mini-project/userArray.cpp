#include "userArray.hpp"
#include <iostream>
#include <cstring>

const int INIT_SIZE = 16;
const int EMPTY = -1;

UserArray::UserArray()
{
    users = new User[INIT_SIZE];
    this->size = size;
    top = EMPTY;

    defaultAdmin.setFirstName("Default");
    defaultAdmin.setLastName("Admin");
    defaultAdmin.setPosition("Admin");
    add(defaultAdmin);
}

UserArray::UserArray(int size)
{
    users = new User[size];
    this->size = size;
    top = EMPTY;

    defaultAdmin.setFirstName("Default");
    defaultAdmin.setLastName("Admin");
    defaultAdmin.setPosition("Admin");
    add(defaultAdmin);
}

UserArray::~UserArray()
{
    //TODO
}

bool UserArray::full() {return top == size - 1;}
bool UserArray::empty() {return top == EMPTY;}
void UserArray::resize()
{
    int newSize = size * 2;
    User* newUsers = new User[newSize];

    for(int i = 0; i < size; i++)
        newUsers[i] = users[i];
    
    size = newSize;
    delete[] users;
    users = newUsers;
}

void UserArray::add(const User &user)
{
    if(full())
        resize();
    
    users[++top] = user;
}

void UserArray::addBy(User &contributor, const User &toBeAdded, const char* password)
{
    //the higher the position the lower the number
    if(contributor.getStatus() <= toBeAdded.getStatus() && contributor.authenticate(password))
        add(toBeAdded);
}

//Remove by fist name (TODO remove by id)
void UserArray::remove(int id)
{
    if(empty())
        return;
    
    // for(int i = 0; i <= top; i++)
    // {
    //     if(strcmp(name,users[i].getFirstName()) == 0)
    //     {
    //         users[i] = users[top--];
    //         return;
    //     }
    // } 
    if(getUserById(id))
        users[id] = users[top--];
}

void UserArray::removeBy(User &contributor, int toBeRemovedID, const char* password)
{
    if(contributor.getStatus() <= getUserById(toBeRemovedID)->getStatus() && contributor.authenticate(password))
        remove(toBeRemovedID);
}

void UserArray::printList()
{
    for(int i = 0; i <= top; i++)
    {
        users[i].printInfo();
        std::cout << std::endl;
    }
}

User* UserArray::getUserById(int id)
{
    if(id >= 0 && id <= top)
    {
        return &users[id];
    }
    return nullptr;
}