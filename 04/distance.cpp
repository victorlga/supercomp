#include <iostream>
#include <cmath> // Para a função sqrt() e pow()
#include <vector>
using namespace std;

// Função para calcular a distância de Euclides entre dois pontos
double calcularDistanciaEuclides(double x1, double y1, double x2, double y2) {
    // Calcula a diferença entre as coordenadas x e y, respectivamente
    double dx = x2 - x1;
    double dy = y2 - y1;

    // Retorna a raiz quadrada da soma dos quadrados das diferenças
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main() {

    int n_linhas;
    cout << "Quantas linhas tem a matriz? ";
    cin >> n_linhas;

    int n_colunas;
    cout << "Quantas colunas tem a matriz? ";
    cin >> n_colunas;

    vector<int> vec(0);
    double distancia;
    int x1, y1, x2, y2;

    for (int i=0; i < n_linhas*n_colunas; i++) {
        for (int j=i+1; j < n_linhas*n_colunas; j++) {
            
        }
    }

    distancia = calcularDistanciaEuclides(x1, y1, x2, y2);

    return 0;
}
