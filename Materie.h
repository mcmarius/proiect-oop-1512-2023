//
// Created by marius on 13.03.2023.
//

#ifndef OOP_MATERIE_H
#define OOP_MATERIE_H

#include <iostream>
#include <string>
#include <iomanip>

class Materie {
    std::string nume = "OOP";
public:
    Materie();
    /*Materie(const Materie& other) : nume(other.nume) {
        std::cout << "constr de copiere materie\n";
    }*/
    /*Materie& operator=(const Materie& other) {
        nume = other.nume;
        return *this;
    }*/
    friend std::ostream& operator<<(std::ostream& os, const Materie& mat);
};



#endif //OOP_MATERIE_H
