#include <omp.h>

int main() // Correct function declaration
{
    #pragma omp parallel
    {
        int num = 0;
        while (true) { // More conventional way of writing an infinite loop
            num += 1;
        }   
    }

    return 0;
}

