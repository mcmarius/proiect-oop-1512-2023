//
// Created by marius on 13.03.2023.
//

#include "Etaj.h"

std::ostream &operator<<(std::ostream &os, const Etaj &etaj) {
    os << "sali:";
    for(const auto& sala : etaj.sali)
        os << sala;
    os << " nr: " << etaj.nr;
    return os;
}
