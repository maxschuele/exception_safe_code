#include <expected>
#include <iostream>

enum class value_error {
    out_of_range,
    is_zero
};

auto f(int value) -> std::expected<int, value_error> {
    if (value == 0) {
        return std::unexpected(value_error::is_zero);
    } else if (value < 0) {
        return std::unexpected(value_error::out_of_range);
    } 
    return value+1;
}
 
int main() {
    auto res = f(5);

    if (res.has_value()) {
        std::cout << "value: " << *res << '\n';
    } else if (res.error() == value_error::is_zero) {
        std::cout << "zero value\n";
    } else if (res.error() == value_error::out_of_range) {
        std::cout << "out of range\n";
    }
}