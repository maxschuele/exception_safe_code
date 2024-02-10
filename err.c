#include <stdio.h>

int divide(int a, int b, int *result) {
  if (b == 0) {
    return -1; // Error code indicating division by zero
  }
  *result = a / b;
  return 0; // Success
}

int main() {
  int result;
  int status = divide(5, 0, &result);
  if (status == -1) {
    printf("Error: Division by zero\n");
    return status;
  }
  printf("Result: %d\n", result);
  return 0;
}