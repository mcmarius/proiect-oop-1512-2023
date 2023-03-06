#include <iostream>
#include <vector>
#include <iomanip>

#ifdef __linux__
#include <X11/Xlib.h>
#endif


class Materie {
    std::string nume = "OOP";
public:
    Materie() {
        //std::cout << "constr implicit materie\n";
    }
    Materie(const Materie& other) : nume(other.nume) {
        std::cout << "constr de copiere materie\n";
    }
    friend std::ostream& operator<<(std::ostream& os, const Materie& mat) {
        os << "{ Nume: " << std::quoted(mat.nume) << "}\n";
        return os;
    }
};

class Student {
    std::string nume;// = "test";
    int grupa;// = 100;
    std::vector<Materie> materii;
public:
    Student() {
        std::cout << "constr implicit student\n";
    }
    Student(std::string nume_, int grupa_, const std::vector<Materie>& materii_) :
            nume{nume_}, grupa(grupa_), materii(materii_) {
//        nume = nume_;
//        grupa = grupa_;
//        materii = materii_;
        std::cout << "constr de inițializare student\n";
    }
    Student(const Student& other) : nume(other.nume), grupa(other.grupa), materii(other.materii) {
//        nume = other.nume;
//        grupa = other.grupa;
//        materii = other.materii;
        std::cout << "constr de copiere student\n";
    }
    Student& operator=(const Student& other) {
        nume = other.nume;
        grupa = other.grupa;
        materii = other.materii;
        std::cout << "operator= student\n";
        return *this;
    }
    ~Student() {
        std::cout << "destr student\n";
    }
    std::ostream& operator<<(std::ostream& os) {
        os << "op<< fără friend: " << this->grupa << " " << this->nume << "\n";
        return os;
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& st);
    void setGrupa(int grupa_) {
        grupa = grupa_;
    }
    std::string getNume() { return nume; }
    int getGrupa() { return grupa; }
};

std::ostream &operator<<(std::ostream &os, const Student &st) {
    os << "Nume: " << st.nume << ", grupa: " << st.grupa << "\n";
    os << "Materii:\n";
    for(const auto& materie : st.materii)
        os << "\tMaterie: " << materie;
    os << "\n";
    return os;
}


void f(Student st) {
    std::cout << "f: " << st.getNume() << "\n";
}

Student g() {
    Student tmp = Student{"test f", 321, {}};
    std::cout << "g: " << tmp.getGrupa() << "\n";
    return tmp; }

int main() {
#ifdef __linux__
    XInitThreads();
#endif

    Student st1, st2{}, st3{st2}, st4(st3), st5 = st1;//, st6();
    Student st7{"test 7", 123, {}};
    Student st8{"test 8", 124, {Materie{}, Materie{}, Materie{}}}, st9{st8};
    std::cout << st8;
    st8.operator<<(std::cout);
    st8 << std::cout;
    std::cout << "------------- st7 -------------\n";
    std::cout << st7.getNume() << " " << st7.getGrupa() << "\n";
    std::cout << "-------------- st8 ------------\n";
    std::cout << st8.getNume() << " " << st8.getGrupa() << "\n";
    st8 = st7 = st5;
    st8.operator=(st7.operator=(st5));
    std::cout << "-------------- st8 din nou ------------\n";
    std::cout << st8.getNume() << " " << st8.getGrupa() << "\n";
    std::cout << "-------------- st9 ------------\n";
    std::cout << st9.getNume() << " " << st9.getGrupa() << "\n";
    std::cout << "-------------- st9 end ------------\n";
    f(st8);
    Student s10{g()};
    std::cout << "dupa apel g\n";
    int a;
    st1 = st2;
//    st6();
//    st1.nume = "test 2";
    std::cout << st1.getNume() << " " << st1.getGrupa() << "\n";
//    st1.setNume("Test 2");
    std::cout << st1.getNume() << " " << st1.getGrupa() << "\n";
    st1.setGrupa(1512);
    std::cout << st1.getNume() << " " << st1.getGrupa() << "\n";
    return 0;
}
