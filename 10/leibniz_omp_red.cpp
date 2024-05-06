#include <iostream>
#include <omp.h>

int main()
{
    int n = 1000000000;
    double sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++)
        sum += (i % 2 == 0 ? 1 : -1) * 1.0 / (2 * i + 1);
    sum *= 4;

    std::cout << sum << "\n";

    return 0;
}