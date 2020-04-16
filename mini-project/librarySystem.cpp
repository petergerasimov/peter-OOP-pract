#include "librarySystem.hpp"

LibrarySystem::LibrarySystem()
{
    currentUser = *users.getUserById(0);
}

LibrarySystem::~LibrarySystem()
{
    
}

//Unused for now
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

int LibrarySystem::command()
{
    std::cout << "Enter command: ";

    resetCursor();
    std::cin.getline(input, MAX_COMMAND_SIZE);

    if(isNextWord("list"))
    {
        if(isNextWord("all"))
        {
            if(isNextWord("users"))
            {
                users.printList();
                return 0;
            }
        }
        else if(isCurrWord("books"))
        {
            books.printList();
            return 0;
        }
        else if(isCurrWord("magazines"))
        {
            magazines.printList();
            return 0;
        }
    }
    else if(isCurrWord("whoami"))
    {
        std::cout << currentUser.getFirstName() << std::endl;
        return 0;
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
            return 0;
        }
        else if(isCurrWord("book")) // add book Name Author ISBN Pages TODO: ISSUE DATE
        {
            Book temp;
            extractString(cmd);
            temp.setName(cmd);

            extractString(cmd);
            temp.setAuthor(cmd);

            extractString(cmd);
            temp.setISBN(atoi(cmd));

            extractString(cmd);
            temp.setPages(atoi(cmd));

            temp.setIssueDate({1,1,2000});
            temp.setAddedBy(currentUser);

            books.add(temp);
            return 0;
        }
        else if(isCurrWord("magazine")) // add book Name Author ISBN TODO: ISSUE DATE
        {
            Magazine temp;
            extractString(cmd);
            temp.setName(cmd);

            extractString(cmd);
            temp.setAuthor(cmd);

            extractString(cmd);
            temp.setISBN(atoi(cmd));

            temp.setIssueDate({1,1,2000});
            temp.setAddedBy(currentUser);

            magazines.add(temp);
            return 0;
        }
    }
    else if(isCurrWord("exit"))
    {
        std::cout << "exiting...\n";
        return 1;
    }

    std::cout << "Unknown command\n";
    return 0;
}