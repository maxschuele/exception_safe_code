#include <exception>
#include <iostream>

void f() noexcept {}
void g() noexcept(false){};

class Terminates {
  public:
    ~Terminates() { throw std::exception(); }
};

class Throws {
  public:
    ~Throws() noexcept(false) { throw std::exception(); }
};

int main() {
    try {
        Throws t;
    } catch (const std::exception &e) {
        std::cout << "caught exception in t" << std::endl;
    }

    try {
        Terminates t2;
    } catch (const std::exception &e) {
    }
}