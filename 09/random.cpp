#include <random>
#include <iostream>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> int_distr(0, 99);
    std::cout << int_distr(gen) << std::endl;

    std::uniform_real_distribution<> real_distr(0.0, 1.0);
    std::cout << real_distr(gen) << std::endl;

    return 0;
}
