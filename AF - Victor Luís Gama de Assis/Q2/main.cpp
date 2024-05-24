#include <mpi.h>
#include <omp.h>
#include <iostream>
#include <vector>
#include <random>


int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int vector_size = 100000;
    int chunk_size = vector_size / size; // On .slurm, make sure that vector_size is a multiple of size.

    std::vector<int> numbers(vector_size);

    if (rank == 0) {
        // Apenas uns testes de sanidade
        std::cout << "Number of MPI processes is " << size << std::endl;
        std::cout << "Max number of OMP threads is " << omp_get_max_threads() << std::endl;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0, 10);

        int sequential_global_sum = 0;
#pragma omp parallel for reduction(+:sequential_global_sum)
        for (int& num : numbers) {
            num = distr(gen);
            sequential_global_sum += num * num;
        }

        // Outro teste de sanidade
        std::cout << "Sequential global sum value is " << sequential_global_sum << std::endl;
    }

    std::vector<int> local_numbers(chunk_size);

    MPI_Scatter(numbers.data(), chunk_size, MPI_INT, local_numbers.data(), chunk_size, MPI_INT, 0, MPI_COMM_WORLD);
    
    int global_sum;
    int local_sum = 0;

#pragma omp parallel for reduction(+:local_sum)
    for (int& num : local_numbers) {
        local_sum += num * num;
    }

    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        std::cout << "Global sum value is " << global_sum << std::endl;
    }

    MPI_Finalize();
    return 0;
}