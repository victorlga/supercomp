#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <omp.h>

const int N = 1000;  // Dimension of the matrix

void matrixMultiply(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B, std::vector<std::vector<double>>& C) {
#pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    std::cout << "Matrix size is " << N << " x " << N << std::endl;
    // Initialize matrices
    std::vector<std::vector<double>> A(N, std::vector<double>(N));
    std::vector<std::vector<double>> B(N, std::vector<double>(N));
    std::vector<std::vector<double>> C(N, std::vector<double>(N));

    // Randomly assign values to A and B
    srand(time(NULL));
#pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }

    // Perform matrix multiplication
     // Timing the multiplication
    double start_time = omp_get_wtime();
    matrixMultiply(A, B, C);
    double time_taken = omp_get_wtime() - start_time;
    std::cout << "Time taken for matrix multiplication: " << time_taken << " seconds." << std::endl;

    return 0;
}
