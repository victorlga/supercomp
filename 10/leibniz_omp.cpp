#include <iostream>
#include <omp.h>

int main()
{
    int n = 1000000000;
    double sum = 0;

    #pragma omp parallel num_threads(2)
    {
        int id, nthreads, istart, iend;
        id = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        istart = id * n / nthreads;
        iend = (id + 1) * n / nthreads;

        double local_sum = 0.0;
        for (int i = istart; i < iend; i++)
            local_sum += (i % 2 == 0 ? 1 : -1) * 1.0 / (2 * i + 1);

        #pragma omp critical
        sum += local_sum;
    }

    sum *= 4;
    std::cout << sum << "\n";

    return 0;
}