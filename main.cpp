#include "Contact.h"
#include <iostream>

int main() {
    const std::string filename = "phonebook.txt";


    loadFromFile(filename);

    int choice;

    do {
        std::cout << "\nPhone Book Menu:\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Search Contact\n";
        std::cout << "3. Delete Contact\n";
        std::cout << "4. View All Contacts\n";
        std::cout << "5. Save Contacts\n";
        std::cout << "6. Load Contacts\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                viewAllContacts();
                break;
            case 5:
                saveToFile(filename);
                break;
            case 6:
                loadFromFile(filename);
                break;
            case 7:
                saveToFile(filename);
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout<<"invalid choice. pls try again" << std::endl;
                break;

        }
    } while (choice != 7);

    return 0;
}