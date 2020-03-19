#ifndef _DATE_HPP
#define _DATE_HPP

class Date
{
    private:
        unsigned day;
        unsigned month;
        int year;
    public:
        Date();
        Date(unsigned day, unsigned month, int year);
        void set(unsigned day, unsigned month, int year);
        void print();
};

#endif