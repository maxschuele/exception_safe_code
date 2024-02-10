class Exception {};
class SpecialException : public Exception {};

int main() {
    try {
        throw SpecialException();
    } catch (const Exception e) {
        // e is of type Exception
    }

    try {
        throw SpecialException();
    } catch (const Exception &e) {
        // e is of type Special Exception
    }
}