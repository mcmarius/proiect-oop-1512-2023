//
// Created by marius on 13.03.2023.
//

#include "Materie.h"

Materie::Materie() {
    //std::cout << "constr implicit materie\n";
}

std::ostream &operator<<(std::ostream &os, const Materie &mat) {
    os << "{ Nume: " << std::quoted(mat.nume) << "}\n";
    return os;
}
