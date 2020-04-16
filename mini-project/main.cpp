#include <iostream>
#include "user.hpp"
#include "userArray.hpp"
#include "date.hpp"
#include "librarySystem.hpp"

int main()
{
    LibrarySystem lib;
    
    while(lib.command() == 0);

    return EXIT_SUCCESS;
}