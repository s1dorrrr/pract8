#ifndef APARTMENT_H
#define APARTMENT_H

#include <iostream>
#include <string>
#include <regex>

class Apartment {
public:
    std::string ownerName;
    std::string address;
    int rooms;
    double area;
    int floor;
    bool balcony;

    Apartment();
    void input();
    void display() const;
};

#endif // APARTMENT_H
