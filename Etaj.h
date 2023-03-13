//
// Created by marius on 13.03.2023.
//

#ifndef OOP_ETAJ_H
#define OOP_ETAJ_H

#include <vector>
#include "Sala.h"

class Etaj {
    std::vector<Sala> sali;
    //Sala sala;
    int nr = 1;
public:
//    Etaj(const std::vector<Sala> &sala, int nr) : sala(sala), nr(nr) {}
    friend std::ostream &operator<<(std::ostream &os, const Etaj &etaj);

};


#endif //OOP_ETAJ_H
