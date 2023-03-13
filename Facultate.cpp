//
// Created by marius on 13.03.2023.
//

#include "Facultate.h"

Facultate::Facultate(const std::string &nume, const std::string &specializare, int ani) : nume(nume),
                                                                                          specializare(specializare),
                                                                                          ani(ani) {}

Facultate::Facultate(const Facultate &other) : nume(other.nume), specializare(other.specializare), ani(other.ani) {
    std::cout << "constr de copiere facultate\n";
}

Facultate &Facultate::operator=(const Facultate &other) {
    std::cout << "op= facultate\n";
    nume = other.nume;
    specializare = other.specializare;
    ani = other.ani;
    return *this;
}

Facultate::~Facultate() {
    std::cout << "destr facultate\n";
}

std::ostream &operator<<(std::ostream &os, const Facultate &facultate) {
    os << "nume: " << facultate.nume << " specializare: " << facultate.specializare << " ani: " << facultate.ani;
    return os;
}
