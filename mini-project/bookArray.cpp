#include "bookArray.hpp"
#include <iostream>
#include <cstring>

const int INIT_SIZE = 16;
const int EMPTY = -1;

BookArray::BookArray()
{
    books = new Literature[INIT_SIZE];
    this->size = size;
    top = EMPTY;
}

BookArray::BookArray(int size)
{
    books = new Literature[size];
    this->size = size;
    top = EMPTY;
}

BookArray::~BookArray()
{
    //TODO
}

bool BookArray::full() {return top == size - 1;}
bool BookArray::empty() {return top == EMPTY;}
void BookArray::resize()
{
    int newSize = size * 2;
    Literature* newBooks = new Literature[newSize];

    for(int i = 0; i < size; i++)
        newBooks[i] = books[i];
    
    size = newSize;
    delete[] books;
    books = newBooks;
}

void BookArray::add(const Literature &book)
{
    if(full())
        resize();
    
    books[++top] = book;
}

void BookArray::remove(int ISBN)
{
    if(empty())
        return;
    
    //This is not tested
    Literature* temp = getBookByISBN(ISBN);
    if(temp)
        *temp = books[top--];
}

void BookArray::printList()
{
    for(int i = 0; i <= top; i++)
    {
        std::cout << books[i].getISBN() << ": " 
                  << books[i].getName() << " " 
                  << books[i].getAuthor()  << " ";
        books[i].getIssueDate().print();
        std::cout << std::endl;
        
    }
}

Literature* BookArray::getBookByISBN(int ISBN)
{
    for(int i = 0; i < top; i++)
    {
        if(books[i].getISBN() == ISBN)
            return &books[i];
    }
    return nullptr;
}

