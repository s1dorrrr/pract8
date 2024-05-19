#include <iostream>
#include "ApartmentManager.h"

void displayMenu() {
    setlocale(LC_ALL, "en_US.UTF-8");
    std::cout << "Menu:\n"
        << "1. Add an apartment\n"
        << "2. Edit an apartment\n"
        << "3. Delete an apartment\n"
        << "4. Search for an apartment\n"
        << "5. Generate a report\n"
        << "6. Exit\n"
        << "Choose an action: ";
}

void displaySearchMenu() {
    std::cout << "Search by:\n"
        << "1. Owner name\n"
        << "2. Address\n"
        << "3. Number of rooms\n"
        << "Choose a search criteria: ";
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    ApartmentManager manager;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

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
            displaySearchMenu();
            int searchChoice;
            std::cin >> searchChoice;
            std::cin.ignore();
            if (searchChoice == 1) {
                std::string ownerFragment;
                std::cout << "Enter owner name fragment: ";
                std::getline(std::cin, ownerFragment);
                manager.searchApartments("owner", ownerFragment);
            }
            else if (searchChoice == 2) {
                std::string addressFragment;
                std::cout << "Enter address fragment: ";
                std::getline(std::cin, addressFragment);
                manager.searchApartments("address", addressFragment);
            }
            else if (searchChoice == 3) {
                int roomCount;
                std::cout << "Enter number of rooms: ";
                std::cin >> roomCount;
                manager.searchApartments("rooms", roomCount);
            }
            else {
                std::cout << "Invalid choice. Please try again.\n";
            }
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
