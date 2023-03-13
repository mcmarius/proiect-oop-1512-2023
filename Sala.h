//
// Created by marius on 13.03.2023.
//

#ifndef OOP_SALA_H
#define OOP_SALA_H

#include <iostream>

class Sala {
public:
    Sala() = default;
    Sala(const Sala& other) = default;
    Sala& operator=(const Sala& other) = default;
    ~Sala() = default;

    friend std::ostream &operator<<(std::ostream &os, const Sala &) {
        return os;
    }
};


#endif //OOP_SALA_H
