#include "IntegerMatrixTests.h"

int main() 
{
    // test 100 x 100, 200 x 200, 300 x 300... square matrices being multiplied
    std::vector<size_t> square_matrices = { 100, 200, 300, 500, 1000, 1500, 2000 };
    IntegerMatrixTests tests(square_matrices);
    tests.RunTests();
}
