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
}

void Date::set(unsigned day, unsigned month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::print()
{
    std::cout << day << "/" << month << "/" << year;
}

// Date& Date::operator=(Date& a)
// {
//     return *this;
// }

Date& Date::operator+(Date& a)
{
    Date temp = *this;
    temp.day += a.day;
    temp.month += a.month;

    //I feel lazy -> every month has 30 days for now
    while(day > 30)
    {
        temp.day-=30;
        temp.month++;
    }
    while(month > 12)
    {
        temp.month-=12;
        temp.year++;
    }
    return temp;
    
}