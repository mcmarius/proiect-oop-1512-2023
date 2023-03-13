//
// Created by marius on 13.03.2023.
//

#ifndef OOP_FACULTATE_H
#define OOP_FACULTATE_H


#include <string>
#include <iostream>

class Facultate {
    std::string nume = "FMI";
    std::string specializare = "Master AI";
    int ani = 2;
public:
    Facultate(const std::string &nume, const std::string &specializare, int ani);

    Facultate(const Facultate& other);
    Facultate& operator=(const Facultate& other);

    ~Facultate();

    friend std::ostream &operator<<(std::ostream &os, const Facultate &facultate);
};



#endif //OOP_FACULTATE_H
