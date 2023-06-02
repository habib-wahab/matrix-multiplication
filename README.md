# Matrix Multiplication 

This program tests the speedup of multiplying varying size of matrices using two different matrix multiplication functions, one sequential and the other parallel. The main goal is to compare the performance of these two methods by measuring the execution time.

## Functions

The program contains two primary functions for matrix multiplication:

1. `IntegerMatrix SequentialMatrixMultiplication(const IntegerMatrix& m);`
2. `IntegerMatrix ParallelMatrixMultiplication(const IntegerMatrix& m);`

These functions take a constant reference to an `IntegerMatrix` object and return the result of the sequential / parallel matrix multiplication as an `IntegerMatrix` object.

## Sample Output

```
Matrix size: 100x100
Sequential Elapsed time: 0 ms
Parallel Elapsed time: 20 ms
Speedup: 0
--------------------------------------
Matrix size: 200x200
Sequential Elapsed time: 7 ms
Parallel Elapsed time: 39 ms
Speedup: 0.179487
--------------------------------------
Matrix size: 300x300
Sequential Elapsed time: 24 ms
Parallel Elapsed time: 71 ms
Speedup: 0.323944
--------------------------------------
Matrix size: 500x500
Sequential Elapsed time: 118 ms
Parallel Elapsed time: 115 ms
Speedup: 1.02609
--------------------------------------
Matrix size: 1000x1000
Sequential Elapsed time: 1068 ms
Parallel Elapsed time: 290 ms
Speedup: 3.67931
--------------------------------------
Matrix size: 1500x1500
Sequential Elapsed time: 3707 ms
Parallel Elapsed time: 636 ms
Speedup: 5.83622
--------------------------------------
Matrix size: 2000x2000
Sequential Elapsed time: 9431 ms
Parallel Elapsed time: 1169 ms
Speedup: 8.07363
--------------------------------------
```