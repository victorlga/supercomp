#include <mpi.h>
#include <iostream>
#include <vector>
#include <random>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int vector_size = 10000;
    std::vector<int> numbers(vector_size);

    if (rank == 0) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0, 10);

        int sequential_global_sum = 0;

        for (int& num : numbers) {
            num = distr(gen);
            sequential_global_sum += num;
        }

        std::cout << "Sequential global sum value is " << sequential_global_sum << std::endl;
    }

    // 0 é o source do broadcast
    // MPI_Bcast(numbers.data(), vector_size, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(numbers.data(), vector_size, MPI_INT, 0, MPI_COMM_WORLD);

    int chunk_size = vector_size / size;
    int start_idx = rank * chunk_size;
    int end_idx = (rank == size - 1) ? vector_size : start_idx + chunk_size;

    int local_sum = 0;
    for (int i = start_idx; i < end_idx; ++i) {
        local_sum += numbers[i];
    }

    int global_sum = 0;
    // MPI_Reduce(const void* sendbuf, void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm);
    // 0 é o destination do reduce
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Print the global sum at the root process
    if (rank == 0) {
        std::cout << "Global sum value is " << global_sum << std::endl;
    }

    MPI_Finalize();

    return 0;
}
