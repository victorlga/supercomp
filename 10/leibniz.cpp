#include <iostream>

int main()
{
    int n = 1000000000;
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += (i % 2 == 0 ? 1 : -1) * 1.0 / (2 * i + 1);
    sum *= 4;

    std::cout << sum << "\n";
}