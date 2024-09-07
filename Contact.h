#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <vector>

struct Contact {
    std:: string name;
    std:: string phoneNumber;
};

extern std::vector<Contact> phoneBook;


void addContact();
void searchContact();
void deleteContact();
void viewAllContacts();
void saveToFile(const std::string& filename);
void loadFromFile(const std::string& filename);

#endif 