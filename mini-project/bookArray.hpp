#ifndef __BOOK_ARRAY_HPP
#define __BOOK_ARRAY_HPP

#include "book.hpp"

class BookArray
{
    private:
        Book* books;
        int size;
        int top;
        bool full();
        bool empty();
        void resize();
        Book* getBookById(int id);

    public:
        BookArray();
        BookArray(int size);
        ~BookArray();
        void add(const Book &book);
        void remove(int id);
        void list();

};

#endif //__BOOK_ARRAY_HPP