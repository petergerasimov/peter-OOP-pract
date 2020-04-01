#include "book.hpp"
#include <iostream>
#include <cstring>

Book::Book()
{
    name = nullptr;
    author = nullptr;
}

Book::Book(
             const char* name,
             const char* author,
             const int& isbn,
             const int& pages,
             const Date& issueDate,
             const Employee& addedBy
            )
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->author = new char[strlen(author) + 1];
    strcpy(this->author, author);

    this->isbn = isbn;
    this->pages = pages;
    this->issueDate = issueDate;
    //May cause issues
    this->addedBy = addedBy;
}
Book::~Book()
{
    delete[] name;
    delete[] author;
}
//Setters
void Book::setName(const char* name)
{
    //Make a class for string or smth
    if(this->name)
        delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
void Book::setAuthor(const char* author)
{
    if(this->author)
        delete[] this->author;
    this->author = new char[strlen(author) + 1];
    strcpy(this->author, author);
}
void Book::setISBN(const int& isbn)
{
    this->isbn = isbn;
}
void Book::setPages(const int& pages)
{
    this->pages = pages;
}
void Book::setIssueDate(const Date& issueDate)
{
    this->issueDate = issueDate;
}
void Book::setAddedBy(const Employee& addedBy)
{
    //May cause issues
    this->addedBy = addedBy;
}
//Getters
const char* Book::getName()
{
    return name;
}
const char* Book::getAuthor()
{
    return author;
}
int Book::getISBN()
{
    return isbn;
}
int Book::getPages()
{
    return pages;
}
Date Book::getIssueDate()
{
    return issueDate;
}
Employee Book::getAddedBy()
{
    return addedBy;
}