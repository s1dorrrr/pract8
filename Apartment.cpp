#include "Apartment.h"

Apartment::Apartment() : roomCount(0), area(0.0), floor(0), hasBalcony(false) {}

void Apartment::input() {
    std::cout << "Введите ФИО владельца: ";
    std::cin.ignore();
    std::getline(std::cin, ownerName);
    std::cout << "Введите адрес: ";
    std::getline(std::cin, address);
    std::cout << "Введите количество комнат: ";
    std::cin >> roomCount;
    std::cout << "Введите площадь: ";
    std::cin >> area;
    std::cout << "Введите этаж: ";
    std::cin >> floor;
    std::cout << "Есть ли балкон (1 - да, 0 - нет): ";
    std::cin >> hasBalcony;
}

void Apartment::display() const {
    std::cout << "ФИО владельца: " << ownerName << "\n"
        << "Адрес: " << address << "\n"
        << "Количество комнат: " << roomCount << "\n"
        << "Площадь: " << area << "\n"
        << "Этаж: " << floor << "\n"
        << "Балкон: " << (hasBalcony ? "Есть" : "Нет") << "\n";
}
