#include <iostream>
#include <vector>
#include <cstdlib>

// Função para multiplicar duas matrizes
std::vector<std::vector<int>> multiplicarMatrizes(const std::vector<std::vector<int>>& a,
                                                 const std::vector<std::vector<int>>& b,
                                                 int tamanho) {
    
    std::vector<std::vector<int>> c(tamanho, std::vector<int>(tamanho, 0));

    for (int i = 0; i < tamanho; ++i) {

        const std::vector<int>* ai = &a[i];

        for (int j = 0; j < tamanho; ++j) {

            const std::vector<int>* bj = &b[j];
            int soma = 0;

            for (int k = 0; k < tamanho; ++k) {
                soma += (*ai)[k]  * (*bj)[k];
            }

            c[i][j] = soma;
        }
    }

    return c;
}

int main(int argc, char* argv[]) {
    if (argc != 2) { // Verifica se o número de argumentos está correto
        std::cerr << "Uso: " << argv[0] << " <tamanho_da_matriz>" << std::endl;
        return 1;
    }

    // Converte o argumento de linha de comando para inteiro
    int tamanho = std::atoi(argv[1]);

    if (tamanho <= 0) {
        std::cerr << "Por favor, forneça um tamanho de matriz válido (maior que 0)." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> a(tamanho, std::vector<int>(tamanho, 1));
    std::vector<std::vector<int>> b(tamanho, std::vector<int>(tamanho, 2));

    // Multiplicação das matrizes
    // Passei o tamanho da matriz para evitar a necessidade de calcular
    // Se não fosse matriz quadrada, eu passaria cada uma das dimensões individualmente
    auto resultado = multiplicarMatrizes(a, b, tamanho);

    std::cout << "Multiplicação de matrizes concluída." << std::endl;

    return 0;
}