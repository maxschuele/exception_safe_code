#include <iostream>
#include <stdexcept>

void f(int value) {
    if (value < 0) {
        throw std::out_of_range("Value cannot be negative");
    } else if (value == 0) {
        throw std::invalid_argument("Value can not be zero");
    }
    std::cout << value << std::endl;
}

void g() {
    try {
        f(-1);
    } catch (const std::out_of_range &e) {
        throw e;
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
}
