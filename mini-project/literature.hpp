#ifndef _LITERATURE_HPP
#define _LITERATURE_HPP

#include "date.hpp"
#include "user.hpp"

//This class hasn't been tested

class Literature
{
    private:
        char* name;
        char* author;
        int isbn;
        Date issueDate;
        User addedBy;
    public:
        Literature();
        Literature(
             const char* name,
             const char* author,
             const int& isbn,
             const Date& issueDate,
             const User& getAddedBy
            );
        ~Literature();
        Literature& operator=(const Literature& a);
        //Setters
        void setName(const char* name);
        void setAuthor(const char* author);
        void setISBN(const int& isbn);
        void setIssueDate(const Date& issueDate);
        void setAddedBy(const User& addedBy);
        //Getters
        const char* getName();
        const char* getAuthor();
        int getISBN();
        Date getIssueDate();
        User getAddedBy();
        
};

#endif //_LITERATURE_HPP