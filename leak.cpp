#include <iostream>
#include <stdexcept>

class Example {
  public:
    Example() { std::cout << "Example constructed\n"; }
    ~Example() { std::cout << "Example destroyed\n"; }
};

void f() {
    Example *ex = new Example();
    throw std::runtime_error("Exception occurred");
    delete ex;
}

int main() {
    try {
        f();
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << '\n';
    }
}
