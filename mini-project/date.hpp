#ifndef _DATE_HPP
#define _DATE_HPP

class Date
{
    private:
        unsigned day;
        unsigned month;
        int year;
        void convertToValid(Date& a);
    public:
        Date();
        Date(unsigned day, unsigned month, int year);
        void set(unsigned day, unsigned month, int year);
        void print();
        // Date& operator=(Date& a);
        Date operator+(const Date& a);

};

#endif