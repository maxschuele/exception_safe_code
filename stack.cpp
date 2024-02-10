#include <exception>
#include <iostream>

class Example {
  private:
    std::string s;

  public:
    Example(const std::string &s) : s(s) {}
    ~Example() { std::cout << s << std::endl; }
};

void f() {
    Example ex1("f()");
    throw std::exception();
}

void g() {
    Example ex2("g()");
    f();
}

void h() {
    Example ex3("h()");
    g();
}

int main() {
    try {
        h();
    } catch (const std::exception &e) {
        std::cout << "caught an exception" << std::endl;
    }
}
