#pragma once

#include "IntegerMatrix.h"
#include <iostream>
#include <vector>
#include <chrono>
#include "Timer.h"

class IntegerMatrixTests {
public:
    explicit IntegerMatrixTests(const std::vector<size_t>& matrix_sizes) : matrix_sizes_(matrix_sizes) {}
    void RunTests()
    {
        for (const auto& size : matrix_sizes_)
            TestMatrixSize(size);
    }
    static std::vector<std::vector<int>> BuildVector(size_t size)
    {
        srand(static_cast<unsigned>(time(NULL)));
        std::vector<std::vector<int>> vec(size, std::vector<int>(size));
        for (size_t i = 0; i < size; i++)
            for (size_t j = 0; j < size; j++)
                vec[i][j] = 1 + rand() % 100;
        return vec;
    }
private:
    void TestMatrixSize(size_t size) {
        std::cout << "Matrix size: " << size << "x" << size << std::endl;
        IntegerMatrix lhs(BuildVector(size));
        IntegerMatrix rhs(BuildVector(size));
        size_t seq_time, par_time;
        {
            Timer timer("Sequential");
            auto sequentially_multiplied_matrix = lhs.SequentialMatrixMultiplication(rhs);
            seq_time = timer.ElapsedTime();
        }
        {
            Timer timer("Parallel");
            auto parallely_multiplied_matrix = lhs.ParallelMatrixMultiplication(rhs);
            par_time = timer.ElapsedTime();
        }
        double speedup = static_cast<double>(seq_time) / par_time;
        std::cout << "Speedup: " << speedup << std::endl;
        std::cout << "--------------------------------------" << std::endl;
    }
    std::vector<size_t> matrix_sizes_;
};
