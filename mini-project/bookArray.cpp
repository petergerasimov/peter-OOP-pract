#include "bookArray.hpp"
#include <iostream>
#include <cstring>

const int INIT_SIZE = 16;
const int EMPTY = -1;

BookArray::BookArray()
{
    books = new Book[INIT_SIZE];
    this->size = size;
    top = EMPTY;
}

BookArray::BookArray(int size)
{
    books = new Book[size];
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
    Book* newBooks = new Book[newSize];

    for(int i = 0; i < size; i++)
        newBooks[i] = books[i];
    
    size = newSize;
    delete[] books;
    books = newBooks;
}

void BookArray::add(const Book &book)
{
    if(full())
        resize();
    
    books[++top] = book;
}

void BookArray::remove(int id)
{
    if(empty())
        return;
    
    if(getBookById(id))
        books[id] = books[top--];
}

void BookArray::list()
{
    for(int i = 0; i <= top; i++)
    {
        std::cout << i << ": " 
                  << books[i].getName() << " " 
                  << books[i].getAuthor()  << " ";
        books[i].getIssueDate().print();
        std::cout << std::endl;
        
    }
}

Book* BookArray::getBookById(int id)
{
    if(id >= 0 && id <= top)
    {
        return &books[id];
    }
    return nullptr;
}

