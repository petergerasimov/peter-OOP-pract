#ifndef _BOOK_HPP
#define _BOOK_HPP

#include "date.hpp"
#include "employee.hpp"

//This class hasn't been tested

class Book
{
    private:
        char* name;
        char* author;
        int isbn;
        int pages;
        Date issueDate;
        Employee addedBy;
    public:
        Book();
        Book(
             const char* name,
             const char* author,
             const int& isbn,
             const int& pages,
             const Date& issueDate,
             const Employee& getAddedBy
            );
        ~Book();
        //Setters
        void setName(const char* name);
        void setAuthor(const char* author);
        void setISBN(const int& isbn);
        void setPages(const int& pages);
        void setIssueDate(const Date& issueDate);
        void setAddedBy(const Employee& addedBy);
        //Getters
        const char* getName();
        const char* getAuthor();
        int getISBN();
        int getPages();
        Date getIssueDate();
        Employee getAddedBy();
        
};

#endif //_BOOK_HPP