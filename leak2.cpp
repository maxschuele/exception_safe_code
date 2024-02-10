#include <exception>

struct CMatrix {
    int *data;           
    unsigned int rows;    
    unsigned int cols;
} ;

void f(unsigned int rows, unsigned int cols) {
    CMatrix m1;
    m1.rows = rows;
    m1.cols = cols;
    m1.data = new int[rows * cols];
    throw std::exception();
    delete[] m1.data;
}

int main() {
    try { 
        f(5,5);
    } catch(const std::exception &e) { 
        //...
    }
}