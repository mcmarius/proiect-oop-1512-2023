#include <iostream>
#include <vector>
#include <iomanip>

#ifdef __linux__
#include <X11/Xlib.h>
#include "Sala.h"
#include "Student.h"
#include "Etaj.h"

#endif






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

//

class baza {
   // derivata d;
};

class derivata : public baza {};


int main() {
    derivata d;
    baza b{d};
#ifdef __linux__
    XInitThreads();
#endif


    Etaj et;
    std::vector<Etaj> etaje;
    etaje.push_back(et);
    Student st1, st2{}, st3{st2}, st4(st3), st5 = st1;//, st6();
    Student st7{"test 7", 123, {}};
    Student st8{"test 8", 124, {Materie{}, Materie{}, Materie{}}}, st9{st8};
    std::cout << st8;
    st8.operator<<(std::cout);
    st8 << std::cout;

    int x;
    std::cin >> x;

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
