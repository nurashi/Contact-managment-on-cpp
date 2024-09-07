#include "Contact.h"
#include <iostream>
#include <fstream>
#include <algorithm>

std::vector<Contact> phoneBook;


void addContact(){
    Contact newContact;
    std::cout << "Enter contact name: ";
    std::cin.ignore();
    std::getline(std::cin, newContact.name);
    std::cout << "Enter phone number: ";
    std::cin >> newContact.phoneNumber;

    phoneBook.push_back(newContact);
    std::cout << "Contact added succ" << std::endl;
}

void searchContact() {
    std::string searchTerm;
    std::cout << "Enter the phone nummber to search ";
    std::cin.ignore();
    std::getline(std::cin, searchTerm);

    bool found = false;
    for(const auto& contact : phoneBook) {
        if (contact.name == searchTerm || contact.phoneNumber == searchTerm){
            std::cout << "contact founded: " << contact.name << " - " << contact.phoneNumber << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "contact is not found" << std::endl;
    }
}
void deleteContact() {
    std::string nameToDelete;
    std::cout << "Enter name of the contact to delete: ";
    std::cin.ignore();
    std::getline(std::cin, nameToDelete);

    auto it = std::remove_if(phoneBook.begin(), phoneBook.end(), [&nameToDelete](const Contact& contact) {
        return contact.name == nameToDelete;
    });

    if (it != phoneBook.end()) {
        phoneBook.erase(it, phoneBook.end());
        std::cout << "Contact Deleted succ" << std::endl;
    } else{
        std::cout << "Contact is not found" << std::endl;
    }
}

void viewAllContacts() {
    if (phoneBook.empty()){
        std::cout << "No contacts available" << std::endl;
        return;
    }
    for (const auto& contact : phoneBook){
        std::cout << contact.name << " - " << contact.phoneNumber << std::endl;
    }
}

void saveToFile(const std::string& filename){
    std::ofstream outFile(filename);
    if (!outFile){
        std::cerr << "Error opening file for writing" << std::endl;
        return;
    }

    for (const auto& contact : phoneBook) {
        outFile << contact.name << std::endl;
        outFile << contact.phoneNumber << std::endl;
    }

    outFile.close();
    std::cout << "Contacts saved successfully." << std::endl;
}

void loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile){
        std::cerr << "Error opening file for reading" << std::endl;
        return;
    }

    phoneBook.clear();
    Contact contact;
    while (std::getline(inFile, contact.name) && std::getline(inFile, contact.phoneNumber)){
        phoneBook.push_back(contact);
    }

    inFile.close();
    std::cout << "Contacts loaded succ" << std::endl;
}

