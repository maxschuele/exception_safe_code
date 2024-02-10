#include <iostream>

class CustomException : public std::exception {
  public:
    const char *what() const noexcept override {
        return "This is a custom exception!";
    }
};

void doSomething(int value) {
    if (value < 0) {
        throw std::out_of_range("Value cannot be negative");
    } else if (value == 0) {
        throw CustomException();
    }

    // Do something with the value
    std::cout << "Value: " << value << std::endl;
}

int main() {
    try {
        // Test with a positive value
        doSomething(42);

        // Test with a negative value
        doSomething(-5);
    } catch (const std::out_of_range &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const CustomException &e) {
        std::cerr << "Caught custom exception: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Caught generic exception: " << e.what() << std::endl;
    }

    return 0;
}