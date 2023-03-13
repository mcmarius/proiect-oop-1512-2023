//
// Created by marius on 13.03.2023.
//

#include "Student.h"

Student::Student() {
    std::cout << "constr implicit student\n";
}

Student::Student(const std::string &nume_, int grupa_, const std::vector<Materie> &materii_) :
        nume{nume_}, grupa(grupa_), materii(materii_) {
//        nume = nume_;
//        grupa = grupa_;
//        materii = materii_;
    std::cout << "constr de inițializare student\n";
}

Student::Student(const Student &other) : nume(other.nume), grupa(other.grupa), materii(other.materii) {
//        nume = other.nume;
//        grupa = other.grupa;
//        materii = other.materii;
    std::cout << "constr de copiere student\n";
}

Student &Student::operator=(const Student &other) {
    nume = other.nume;
    grupa = other.grupa;
    materii = other.materii;
    std::cout << "operator= student\n";
    return *this;
}

Student::~Student() {
    std::cout << "destr student\n";
}

std::ostream &Student::operator<<(std::ostream &os) {
    os << "op<< fără friend: " << this->grupa << " " << this->nume << "\n";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Student &student) {
    os << "facultate: " << student.facultate << " nume: " << student.nume << " grupa: " << student.grupa
       << "\nMaterii:\n";
    for(const auto& materie : student.materii)
        os << "\t" << materie;
    return os;
}

void Student::setGrupa(int grupa_) {
    grupa = grupa_;
}

std::string Student::getNume() { return nume; }

int Student::getGrupa() const { return grupa; }
