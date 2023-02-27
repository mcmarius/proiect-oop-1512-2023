#include <iostream>

class Student {
    std::string nume;// = "test";
    int grupa;// = 100;
public:
    void setNume(std::string nume_) {
        nume = nume_;
    }
    void setGrupa(int grupa_) {
        grupa = grupa_;
    }
    std::string getNume() { return nume; }
    int getGrupa() { return grupa; }
};

int main() {
    Student st1, st2{}, st3{st2}, st4(st3), st5 = st1;//, st6();
    int a;
    st1 = st2;
//    st6();
//    st1.nume = "test 2";
    std::cout << st1.getNume() << " " << st1.getGrupa() << "\n";
    st1.setNume("Test 2");
    std::cout << st1.getNume() << " " << st1.getGrupa() << "\n";
    st1.setGrupa(1512);
    std::cout << st1.getNume() << " " << st1.getGrupa() << "\n";
    return 0;
}
