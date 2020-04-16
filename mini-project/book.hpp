#ifndef __BOOK_HPP
#define __BOOK_HPP

#include "literature.hpp"

class Book : public Literature
{
    private:
        int pages;
    public:
        //Maybe it's bad practice but it's such a small class I didn't feel the need of a cpp file
        void setPages(const int& pages)
        {
            this->pages = pages;
        }
        int setPages()
        {
            return this->pages;
        }
};

#endif //__BOOK_HPP