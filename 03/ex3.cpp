#include <iostream>
#include <vector>
using namespace std;

void construir(vector<int> &v, int t);
void ordenar(vector<int> &v, int t);
void imprimir(vector<int> &v);

int main() {

    int tamanho;
    cout << "Informe o tamnho do vetor: ";
    cin >> tamanho;

    vector<int> vetor;

    construir(vetor, tamanho);
    imprimir(vetor);
    ordenar(vetor, tamanho);
    imprimir(vetor);

    return 0;
}

void construir(vector<int> &v, int t) {

    int aux;
    for (int i = 0; i < t; i++) {
        cout << "Digite um falor para a posição " << i << ": ";
        cin >> aux;
        v.push_back(aux);
    }
}

void ordenar(vector<int> &v, int t) {

    for (int i = 1; i < t; i++) {
        int temp = v[i];

        int j = i;
        while (j > 0 && v[j - 1] > temp) {
            v[j] = v[j - 1];
            j--;
        }

        v[j] = temp;
    }
}


void imprimir(vector<int> &v) {

    cout << "Valores do vetor: ";

    for (int num : v) {
        cout << num << " ";
    }

    cout << "\n";

}
