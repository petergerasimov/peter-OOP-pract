#ifndef _User_HPP
#define _User_HPP

enum USER_STATUS {admin, employee, user};

class User
{
    private:
        char* firstName;
        char* lastName;
        char* position;
        char* password = nullptr;
        USER_STATUS status;
    public:
        User();
        User(const char* firstName,
                 const char* lastName,
                 const char* position,
                 USER_STATUS status
                );
        ~User();

        //Utils
        User& operator=(const User& a);

        //Setters
        void setFirstName(const char* firstName);
        void setLastName(const char* lastName);
        void setPosition(const char* position);
        void setStatus(USER_STATUS status);
        void setPassword(const char* password);

        //Getters
        const char* getFirstName() const;
        const char* getLastName() const;
        const char* getPosition() const;
        const USER_STATUS getStatus() const;
        bool authenticate(const char* password);




};

#endif