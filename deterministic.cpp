#include <iostream>

int f(int value) throws {
    if (value == 0) throw value_error::is_zero;
    if (value < 0) throw value_error:out_of_range;
}

int g() throws { return f() + 1; }

int main() {
    try {
        auto result = g();
    } catch(error err) {
        if (e == value_error::is_zero)
            return 0;
        if (e == value_error::out_of_range)
            // ...
    }
}