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