#include "librarySystem.hpp"

LibrarySystem::LibrarySystem()
{
    currentUser = *users.getUserById(0);
}

LibrarySystem::~LibrarySystem()
{
    
}

void LibrarySystem::update()
{
    command();
}

void LibrarySystem::resetCursor()
{
    cursor = 0;
}

void LibrarySystem::extractString(char* str)
{
    int i = 0;
    for (; input[cursor] != 0 &&
           input[cursor] != ' ' &&
           input[cursor] != '\n';
           cursor++
        )
        str[i++] = input[cursor];
    

    str[i] = 0;

    if (input[cursor] != 0)
        cursor++;
}

bool LibrarySystem::isNextWord(const char *word)
{
    extractString(cmd);
    return strcmp(cmd, word) == 0;
}

bool LibrarySystem::isCurrWord(const char *word)
{
    return strcmp(cmd, word) == 0;
}

void LibrarySystem::command()
{
    std::cout << "Enter command: ";

    resetCursor();
    std::cin.getline(input, MAX_COMMAND_SIZE);

    if(isNextWord("list"))
    {
        users.list();
    }
    else if(isCurrWord("whoami"))
    {
        std::cout << currentUser.getFirstName() << std::endl;
    }
    else if(isCurrWord("add"))
    {
        if(isNextWord("user")) // Syntax is add user firstName lastName position theirPassword yourPassword
        {
            User temp;

            extractString(cmd);
            temp.setFirstName(cmd);

            extractString(cmd);
            temp.setLastName(cmd);

            extractString(cmd);
            temp.setPosition(cmd);

            extractString(cmd);
            temp.setPassword(cmd);

            temp.setStatus(user);
            //extractString(cmd); //no password for now
            users.addBy(currentUser, temp);
        }
        else if(isCurrWord("book"))
        {

        }
    }
    else if(isCurrWord("exit"))
    {
        std::cout << "exiting...\n";
        //to do
    }
    else
    {
        std::cout << "Unknown command\n";
    }
    
}