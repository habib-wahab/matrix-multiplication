#include "IntegerMatrixTests.h"

int main() 
{
    std::vector<size_t> square_matrices = { 100, 200, 300, 500, 1000, 1500, 2000 };
    IntegerMatrixTests tests(square_matrices);
    tests.RunTests();
}
