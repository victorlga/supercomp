#include <iostream>
#include <random>
#include <omp.h>

int main()
{
    int sum = 0;
    int n = 10000000;

    #pragma omp parallel
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 1);

        int local_sum = 0;
        double x, y;

        #pragma omp for
        for (int i = 0; i < n; i++)
        {
            x = dis(gen);
            y = dis(gen);

            if (x * x + y * y <= 1)
            {
                local_sum++;
            }
        }

        #pragma omp atomic
        sum += local_sum;
    }

    double pi = 4.0 * sum / n;
    std::cout << "Estimated value of pi: " << pi << std::endl;

    return 0;
}
