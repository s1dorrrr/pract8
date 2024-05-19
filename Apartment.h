#ifndef APARTMENT_H
#define APARTMENT_H

#include <iostream>
#include <string>

class Apartment {
public:
    std::string ownerName;
    std::string address;
    int roomCount;
    double area;
    int floor;
    bool hasBalcony;

    Apartment();
    void input();
    void display() const;
};

#endif // APARTMENT_H
