#include "ApartmentManager.h"
#include <algorithm>
#include <limits>

int ApartmentManager::findApartmentByOwnerFragment(const std::string& fragment) {
    std::vector<int> matches;
    for (size_t i = 0; i < apartments.size(); ++i) {
        if (apartments[i].ownerName.find(fragment) != std::string::npos) {
            matches.push_back(i);
        }
    }

    if (matches.empty()) {
        std::cout << "No matches found.\n";
        return -1;
    }
    else if (matches.size() == 1) {
        return matches[0];
    }
    else {
        std::cout << "Multiple matches found:\n";
        for (size_t i = 0; i < matches.size(); ++i) {
            std::cout << i + 1 << ". ";
            apartments[matches[i]].display();
        }
        int choice;
        std::cout << "Select the number of the desired record: ";
        std::cin >> choice;
        if (choice > 0 && choice <= matches.size()) {
            return matches[choice - 1];
        }
        else {
            std::cout << "Invalid choice.\n";
            return -1;
        }
    }
}

void ApartmentManager::addApartment() {
    Apartment apt;
    apt.input();
    apartments.push_back(apt);
}

void ApartmentManager::editApartment() {
    std::string fragment;
    std::cout << "Enter the owner name fragment for search: ";
    std::cin.ignore();
    std::getline(std::cin, fragment);

    int index = findApartmentByOwnerFragment(fragment);
    if (index != -1) {
        std::cout << "Enter new details:\n";
        apartments[index].input();
    }
}

void ApartmentManager::deleteApartment() {
    std::string fragment;
    std::cout << "Enter the owner name fragment for search: ";
    std::cin.ignore();
    std::getline(std::cin, fragment);

    int index = findApartmentByOwnerFragment(fragment);
    if (index != -1) {
        apartments.erase(apartments.begin() + index);
        std::cout << "Card deleted.\n";
    }
}

void ApartmentManager::searchApartments(const std::string& criteria) {
    std::string loweredCriteria = criteria;
    std::transform(loweredCriteria.begin(), loweredCriteria.end(), loweredCriteria.begin(), ::tolower);
    for (const auto& apt : apartments) {
        std::string loweredOwnerName = apt.ownerName;
        std::string loweredAddress = apt.address;
        std::transform(loweredOwnerName.begin(), loweredOwnerName.end(), loweredOwnerName.begin(), ::tolower);
        std::transform(loweredAddress.begin(), loweredAddress.end(), loweredAddress.begin(), ::tolower);

        if (loweredOwnerName.find(loweredCriteria) != std::string::npos ||
            loweredAddress.find(loweredCriteria) != std::string::npos ||
            (criteria == std::to_string(apt.rooms))) {
            apt.display();
            std::cout << "--------------------\n";
        }
    }
}

void ApartmentManager::generateReport() const {
    std::cout << "Apartment report:\n";
    for (const auto& apt : apartments) {
        apt.display();
        std::cout << "--------------------\n";
    }
}
