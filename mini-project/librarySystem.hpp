#ifndef __LIBRARY_SYSTEM_HPP
#define __LIBRARY_SYSTEM_HPP

#include <iostream>
#include <cstring>
#include "bookArray.hpp"
#include "userArray.hpp"

static const int MAX_COMMAND_SIZE = 256;

class LibrarySystem
{
    private:
        char input[MAX_COMMAND_SIZE];
        char cmd[MAX_COMMAND_SIZE];
        int cursor = 0;
        BookArray books;
        BookArray magazines;
        UserArray users;
        User currentUser;

        void extractString(char* str);
        void resetCursor();
        bool isNextWord(const char *);
        bool isCurrWord(const char *word);
    public:
        LibrarySystem();
        ~LibrarySystem();
        void update();
        int command();
};

#endif //__LIBRARY_SYSTEM_HPP