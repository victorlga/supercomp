#include <iostream>
#include <time.h>
#include <iomanip>
#include <vector>

int fib(int n, std::vector<int>& memo) {
    if (memo[n] != -1) {
        return memo[n];
    }
    
    if (n <= 1) {
        return n;
    } else {
        memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
        return memo[n];
    }
}

int main() {
    int n;

    for (int i = 0; i < 2; ++i) {
        std::cout << "Defina o valor de N: ";
        std::cin >> n;
        std::vector<int> memo = std::vector<int>(n + 1, -1);

        clock_t start = clock();
        int result = fib(n, memo);
        double duration = (double) (clock() - start) / CLOCKS_PER_SEC;

        std::cout << "Fibonacci de " << n << " é " << result << std::endl;
        std::cout << "Tempo para calcular: " << std::setprecision(2) << duration << std::endl << std::endl;
    }

    return 0;
}