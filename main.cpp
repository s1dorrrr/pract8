#include <iostream>
#include "ApartmentManager.h"

void displayMenu() {
    std::cout << "Menu:\n"
        << "1. Add an apartment\n"
        << "2. Edit an apartment\n"
        << "3. Delete an apartment\n"
        << "4. Search for an apartment\n"
        << "5. Generate a report\n"
        << "6. Exit\n"
        << "Choose an action: ";
}

int main() {
    ApartmentManager manager;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка потока ввода после ввода числа

        switch (choice) {
        case 1:
            manager.addApartment();
            break;
        case 2:
            manager.editApartment();
            break;
        case 3:
            manager.deleteApartment();
            break;
        case 4: {
            std::string criteria;
            std::cout << "Enter search criteria (name, address, or number of rooms): ";
            std::getline(std::cin, criteria);
            manager.searchApartments(criteria);
            break;
        }
        case 5:
            manager.generateReport();
            break;
        case 6:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}
