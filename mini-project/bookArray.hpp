#ifndef __BOOK_ARRAY_HPP
#define __BOOK_ARRAY_HPP

#include "literature.hpp"
#include "book.hpp"
#include "magazine.hpp"

class BookArray
{
    private:
        Literature* books;
        int size;
        int top;
        bool full();
        bool empty();
        void resize();
        Literature* getBookByISBN(int ISBN);

    public:
        BookArray();
        BookArray(int size);
        ~BookArray();
        void add(const Literature &book);
        void remove(int ISBN);
        void printList();

};

#endif //__BOOK_ARRAY_HPP