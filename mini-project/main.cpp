#include <iostream>
#include "user.hpp"
#include "userArray.hpp"
#include "date.hpp"
#include "librarySystem.hpp"

int main()
{
    LibrarySystem lib;
    
    for(;;)lib.update();


    return EXIT_SUCCESS;
}