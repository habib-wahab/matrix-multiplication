#include "IntegerMatrix.h"
#include "Timer.h"
#include <chrono>
#include <iostream>

IntegerMatrix::IntegerMatrix(const size_t rows, const size_t columns) : rows_(rows), columns_(columns)
{
    values_.resize(rows, std::vector<int>(columns));
}

IntegerMatrix::IntegerMatrix(const std::vector<std::vector<int>>& values) : values_(values)
{
    rows_ = values.size();
    columns_ = values.at(0).size();
}

IntegerMatrix::IntegerMatrix(const size_t rows, const size_t columns, const std::vector<int>& values) :
    rows_(rows),
    columns_(columns),
    values_(rows, std::vector<int>(columns))
{
    for (size_t i = 0, idx = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            values_[i][j] = values[idx++];
}

IntegerMatrix IntegerMatrix::SequentialMatrixMultiplication(const IntegerMatrix& m)
{
    IntegerMatrix new_matrix(rows_, m.columns_);
    for (size_t i = 0; i < rows_; i++)
    {
        for (size_t j = 0; j < m.columns_; j++)
        {
            new_matrix.values_[i][j] = 0;
            for (size_t k = 0; k < columns_; k++)
                new_matrix.values_[i][j] += values_[i][k] * m.values_[k][j];
        }
    }
    return new_matrix;
}

void IntegerMatrix::MultiplyRowWithColumns(size_t row_index, const IntegerMatrix& m, IntegerMatrix& new_matrix)
{
    for (size_t i = 0; i < columns_; i++)
        for (size_t j = 0; j < m.columns_; j++)
            new_matrix.values_[row_index][j] += values_[row_index][i] * m.values_[i][j];
}

IntegerMatrix IntegerMatrix::ParallelMatrixMultiplication(const IntegerMatrix& m)
{
    IntegerMatrix new_matrix(rows_, m.columns_);
    for (size_t i = 0; i < rows_; i++)
        threads_.push_back(std::thread(&IntegerMatrix::MultiplyRowWithColumns, this, i, std::ref(m), std::ref(new_matrix)));
    for (auto& i : threads_)
        i.join();
    return new_matrix;
}

void IntegerMatrix::Print() const
{
    for (const auto& row : values_)
    {
        for (const auto& value : row)
            std::cout << value << ' ';
        std::cout << '\n';
    }
}
