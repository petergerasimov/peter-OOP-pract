#include "book.hpp"
#include <iostream>
#include <cstring>


//Literature 
Literature::Literature()
{
    name = nullptr;
    author = nullptr;
}

Literature::Literature(
             const char* name,
             const char* author,
             const int& isbn,
             const Date& issueDate,
             const User& addedBy
            )
{
    setName(name);
    setAuthor(author);
    setISBN(isbn);
    this->issueDate = issueDate;
    //May cause issues
    this->addedBy = addedBy;
}
Literature::~Literature()
{
    delete[] name;
    delete[] author;
}

Literature& Literature::operator=(const Literature& a) {
    if(a.name)
        setName(a.name);
    if(a.author)
        setAuthor(a.author);
    setISBN(a.isbn);
    setIssueDate(a.issueDate);

    return *this;
}
//Setters
void Literature::setName(const char* name)
{
    //Make a class for string or smth
    if(this->name)
        delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
void Literature::setAuthor(const char* author)
{
    if(this->author)
        delete[] this->author;
    this->author = new char[strlen(author) + 1];
    strcpy(this->author, author);
}
void Literature::setISBN(const int& isbn)
{
    this->isbn = isbn;
}
void Literature::setIssueDate(const Date& issueDate)
{
    this->issueDate = issueDate;
}
void Literature::setAddedBy(const User& addedBy)
{
    //May cause issues
    this->addedBy = addedBy;
}
//Getters
const char* Literature::getName()
{
    return name;
}
const char* Literature::getAuthor()
{
    return author;
}
int Literature::getISBN()
{
    return isbn;
}
Date Literature::getIssueDate()
{
    return issueDate;
}
User Literature::getAddedBy()
{
    return addedBy;
}