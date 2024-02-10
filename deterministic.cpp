// this code will not compile!
// goal is to show the proposed "Zero-overhead deterministic exceptions"
// https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p0709r4.pdf

int f(int value) throws {
  if (value == 0)
    throw value_error::is_zero;
  if (value < 0)
    throw value_error : out_of_range;
}

int g() throws { return f() + 1; }

int main() {
  try {
    auto result = g();
  } catch (error err) {
    if (e == value_error::is_zero)
      return 0;
    if (e == value_error::out_of_range)
    // ...
  }
}
