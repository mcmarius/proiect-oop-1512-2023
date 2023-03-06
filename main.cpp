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
    /*Materie(const Materie& other) : nume(other.nume) {
        std::cout << "constr de copiere materie\n";
    }*/
    /*Materie& operator=(const Materie& other) {
        nume = other.nume;
        return *this;
    }*/
    friend std::ostream& operator<<(std::ostream& os, const Materie& mat) {
        os << "{ Nume: " << std::quoted(mat.nume) << "}\n";
        return os;
    }
};

class Facultate {
    std::string nume = "FMI";
    std::string specializare = "Master AI";
    int ani = 2;
public:
    Facultate(const std::string &nume, const std::string &specializare, int ani) : nume(nume),
                                                                                   specializare(specializare),
                                                                                   ani(ani) {}

    Facultate(const Facultate& other) : nume(other.nume), specializare(other.specializare), ani(other.ani) {
        std::cout << "constr de copiere facultate\n";
    }
    Facultate& operator=(const Facultate& other) {
        std::cout << "op= facultate\n";
        nume = other.nume;
        specializare = other.specializare;
        ani = other.ani;
        return *this;
    }

    ~Facultate() {
        std::cout << "destr facultate\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const Facultate &facultate) {
        os << "nume: " << facultate.nume << " specializare: " << facultate.specializare << " ani: " << facultate.ani;
        return os;
    }
};

class Student {
    Facultate facultate{"FMI", "Info", 3};
    std::string nume;// = "test";
    int grupa = 100;
    std::vector<Materie> materii;
public:
    Student() {
        std::cout << "constr implicit student\n";
    }
    Student(const std::string& nume_, int grupa_, const std::vector<Materie>& materii_) :
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
//    friend std::ostream& operator<<(std::ostream& os, const Student& st);
    friend std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << "facultate: " << student.facultate << " nume: " << student.nume << " grupa: " << student.grupa
           << "\nMaterii:\n";
        for(const auto& materie : student.materii)
            os << "\t" << materie;
        return os;
    }

    void setGrupa(int grupa_) {
        grupa = grupa_;
    }
    std::string getNume() { return nume; }
    int getGrupa() { return grupa; }
};

//std::ostream &operator<<(std::ostream &os, const Student &st) {
//    os << "Nume: " << st.nume << ", grupa: " << st.grupa << "\n";
//    os << "Materii:\n";
//    for(const auto& materie : st.materii)
//        os << "\tMaterie: " << materie;
//    os << "\n";
//    return os;
//}


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
    // int a;
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
