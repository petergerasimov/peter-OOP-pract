#ifndef _USER_ARRAY_HPP
#define _USER_ARRAY_HPP

#include "user.hpp"

class UserArray
{
    private:
        User* users;
        int size;
        int top;
        bool full();
        bool empty();
        void resize();
        void add(const User &user);
        void remove(int id);
        
        User defaultAdmin;

    public:
        UserArray();
        UserArray(int size);
        ~UserArray();
        
        void addBy(User &contributor, const User &toBeAdded, const char* password = " ");
        //This is not very good
        void removeBy(User &contributor, int toBeRemovedID, const char* password = " ");
        void printList();

        User* getUserById(int id);

};

#endif //_USER_ARRAY_HPP