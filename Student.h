//
// Created by marius on 13.03.2023.
//

#ifndef OOP_STUDENT_H
#define OOP_STUDENT_H


#include <vector>
#include "Facultate.h"
#include "Materie.h"

class Student {
    Facultate facultate{"FMI", "Info", 3};
    std::string nume;// = "test";
    int grupa = 100;
    std::vector<Materie> materii;
public:
    Student();
    Student(const std::string& nume_, int grupa_, const std::vector<Materie>& materii_);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();
    std::ostream& operator<<(std::ostream& os);
//    friend std::ostream& operator<<(std::ostream& os, const Student& st);
    friend std::ostream &operator<<(std::ostream &os, const Student &student);

    void setGrupa(int grupa_);
    std::string getNume();
    int getGrupa() const;
};



#endif //OOP_STUDENT_H
