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
    int chunk_size = vector_size / size;
    std::vector<int> numbers(vector_size);

    if (rank == 0) {
        // Initialize the vector with random numbers
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

    // Each process will receive a chunk of the vector
    std::vector<int> local_chunk(chunk_size);

    // Scatter the chunks to all processes
    // MPI_Scatter(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);
    MPI_Scatter(numbers.data(), chunk_size, MPI_INT, local_chunk.data(), chunk_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process now computes the sum of its local chunk
    int local_sum = 0;
    for (int num : local_chunk) {
        local_sum += num;
    }

    // Gather the local sums back to the root process
    // Seria muito melhor simplesmente usar um Reduce
    std::vector<int> local_sums(size);
    // MPI_Gather(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);
    MPI_Gather(&local_sum, 1, MPI_INT, local_sums.data(), 1, MPI_INT, 0, MPI_COMM_WORLD);

    // The root process computes the global sum
    if (rank == 0) {
        int global_sum = 0;
        for (int sum : local_sums) {
            global_sum += sum;
        }
        std::cout << "Global sum value is " << global_sum << std::endl;
    }

    MPI_Finalize();
    return 0;
}
