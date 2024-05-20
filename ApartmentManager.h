#ifndef APARTMENT_MANAGER_H
#define APARTMENT_MANAGER_H

#include <iostream>
#include <vector>
#include "Apartment.h"

class ApartmentManager {
private:
    std::vector<Apartment> apartments;
    int findApartmentByOwnerFragment(const std::string& fragment);

public:
    void addApartment();
    void editApartment();
    void deleteApartment();
    void searchApartments(const std::string& criteria);
    void generateReport() const;
};

#endif // APARTMENT_MANAGER_H
