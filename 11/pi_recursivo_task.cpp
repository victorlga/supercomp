#include <omp.h>
#include <iostream>
#include <iomanip>
static long num_steps = 1024l*1024*1024*2;

#define MIN_BLK  1024*1024*256

double pi_r(long Nstart, long Nfinish, double step) {
    long i, iblk;
    if (Nfinish - Nstart < MIN_BLK) {
        double sum = 0;
        for (i = Nstart; i < Nfinish; i++) {
            double x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);
        }
        return sum;
    } else {
        iblk = (Nfinish - Nstart) / 2;
        double local_sum_0, local_sum_1;
        #pragma omp task shared(local_sum_0)
        local_sum_0 = pi_r(Nstart, Nstart + iblk, step);
        #pragma omp task shared(local_sum_1)
        local_sum_1 = pi_r(Nstart + iblk, Nfinish, step);
        #pragma omp taskwait
        return local_sum_0 + local_sum_1;
    }
}


int main () {
    double step, pi;
    double init_time, final_time;
    step = 1.0/(double) num_steps;
    init_time = omp_get_wtime();
    double sum;
    #pragma omp parallel
    {
        #pragma omp single
        sum = pi_r(0, num_steps, step);
    }
    pi = step * sum;
    final_time = omp_get_wtime() - init_time;

    std::cout << "for " << num_steps << " steps pi = " << std::setprecision(15) << pi << " in " << final_time << " secs\n";
}