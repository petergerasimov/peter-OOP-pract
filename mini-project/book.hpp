#ifndef _BOOK_HPP
#define _BOOK_HPP

#include "date.hpp"
#include "user.hpp"

//This class hasn't been tested

class Book
{
    private:
        char* name;
        char* author;
        int isbn;
        int pages;
        Date issueDate;
        User addedBy;
    public:
        Book();
        Book(
             const char* name,
             const char* author,
             const int& isbn,
             const int& pages,
             const Date& issueDate,
             const User& getAddedBy
            );
        ~Book();
        //Setters
        void setName(const char* name);
        void setAuthor(const char* author);
        void setISBN(const int& isbn);
        void setPages(const int& pages);
        void setIssueDate(const Date& issueDate);
        void setAddedBy(const User& addedBy);
        //Getters
        const char* getName();
        const char* getAuthor();
        int getISBN();
        int getPages();
        Date getIssueDate();
        User getAddedBy();
        
};

#endif //_BOOK_HPP