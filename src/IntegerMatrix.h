#pragma once

#include <vector>
#include <thread>

class IntegerMatrix
{
public:
    IntegerMatrix() = delete;
    IntegerMatrix(const size_t rows, const size_t columns);
    IntegerMatrix(const std::vector<std::vector<int>>& values);
    IntegerMatrix(const size_t rows, const size_t columns, const std::vector<int>& values);
    IntegerMatrix SequentialMatrixMultiplication(const IntegerMatrix& m);
    IntegerMatrix ParallelMatrixMultiplication(const IntegerMatrix& m);
    void Print() const;
private:
    void MultiplyRowWithColumns(size_t row_index, const IntegerMatrix& m, IntegerMatrix& new_matrix);
    size_t rows_;
    size_t columns_;
    std::vector<std::vector<int>> values_;
    std::vector<std::thread> threads_;
};
