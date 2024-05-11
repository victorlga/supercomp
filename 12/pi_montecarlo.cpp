// Importar lib para gerar números aleatórios
#include <iostream>
#include <random>


int main()
{
    int sum = 0;
    int n = 10000000;

    double x, y;

    // Sorteie pontos de x e y entre 0 e 1
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    for (int i = 0; i < n; i++)
    {
        x = dis(gen);
        y = dis(gen);

        // Verifique se o ponto está dentro do círculo
        if (x * x + y * y <= 1)
        {
            sum++;
        }
    }

    // Calcule pi
    double pi = 4.0 * sum / n;

    std::cout << "Estimated value of pi: " << pi << std::endl;

    return 0;
}