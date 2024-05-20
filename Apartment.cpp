#include "Apartment.h"

Apartment::Apartment() : rooms(0), area(0.0), floor(0), balcony(false) {}

void Apartment::input() {
    std::regex name_regex("^[A-Za-zА-Яа-яЁё ]+$");

    // Ввод имени владельца с проверкой на цифры
    do {
        std::cout << "Enter owner name (letters and spaces only): ";
        std::cin.ignore();
        std::getline(std::cin, ownerName);
        if (!std::regex_match(ownerName, name_regex)) {
            std::cout << "Error: Name can only contain letters and spaces." << std::endl;
        }
    } while (!std::regex_match(ownerName, name_regex));

    std::cout << "Enter address: ";
    std::getline(std::cin, address);

    std::cout << "Enter number of rooms: ";
    while (!(std::cin >> rooms) || rooms <= 0) {
        std::cout << "Error: Enter a valid positive number of rooms." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter area: ";
    while (!(std::cin >> area) || area <= 0) {
        std::cout << "Error: Enter a valid positive area." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter floor: ";
    while (!(std::cin >> floor) || floor <= 0) {
        std::cout << "Error: Enter a valid positive floor number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Has balcony (1 - yes, 0 - no): ";
    while (!(std::cin >> balcony) || (balcony != 0 && balcony != 1)) {
        std::cout << "Error: Enter 1 (yes) or 0 (no)." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Apartment::display() const {
    std::cout << "Owner name: " << ownerName << "\n"
        << "Address: " << address << "\n"
        << "Number of rooms: " << rooms << "\n"
        << "Area: " << area << " sq.m\n"
        << "Floor: " << floor << "\n"
        << "Balcony: " << (balcony ? "Yes" : "No") << "\n";
}
