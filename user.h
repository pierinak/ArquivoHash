#ifndef USER_H
#define USER_H

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

struct User {
    string id;
    string name;
    string contact;

    User() = default;
    User(const string& id, const string& name, const string& contact)
        : id(id), name(name), contact(contact) {}
};

class UserCollection {
public:
    void addUser(const User& user);
    void removeUser(const string& id);
    User* searchUser(const string& id);
    void listUsers() const;

private:
    unordered_map<string, User> users;
};

#endif // USER_H
