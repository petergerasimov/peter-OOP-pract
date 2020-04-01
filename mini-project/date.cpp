#include "date.hpp"
#include <iostream>

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(unsigned day, unsigned month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
    convertToValid(*this);
}

void Date::set(unsigned day, unsigned month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
    convertToValid(*this);
}

void Date::print()
{
    std::cout << day << "/" << month << "/" << year;
}

// Date& Date::operator=(Date& a)
// {
//     return *this;
// }

void Date::convertToValid(Date& a)
{
    //All months are 30 days long for now
    while(a.day > 30)
    {
        a.day-=30;
        a.month++;
    }
    while(a.month > 12)
    {
        a.month-=12;
        a.year++;
    }
}

Date Date::operator+(const Date& a)
{
    Date temp = *this;
    temp.day += a.day;
    temp.month += a.month;
    temp.year += a.year;
    convertToValid(temp);
    return temp;
    
}