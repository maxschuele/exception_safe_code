#include <iostream>
#include <memory>
#include <stdexcept>

class Example {
  public:
    Example() { std::cout << "Example constructed\n"; }
    ~Example() { std::cout << "Example destroyed\n"; }
};

void f() {
    std::unique_ptr<Example> ptr = std::make_unique<Example>();
    throw std::runtime_error("Exception occurred");
}

int main() {
    try {
        f();
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << '\n';
    }
    return 0;
}