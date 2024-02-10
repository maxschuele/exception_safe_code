#include <exception>
#include <iostream>
#include <string>

class CustomException : public std::exception {
  private:
    std::string errMsg;

  public:
    CustomException(const std::string &msg) : errMsg(msg) {}
    const char *what() const noexcept override { return errMsg.c_str(); }
};

void f(int value) {
    if (value == 0) {
        throw CustomException("Value cannot be zero");
    }
    // ...
}

int main() {
    try {
        f(0);
    } catch (const CustomException &e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}