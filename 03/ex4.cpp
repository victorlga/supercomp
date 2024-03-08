#include <iostream>
#include <vector>
using namespace std;

void construir(vector<int> &v, int t);
void ordenar(vector<int> &v, int t);
void buscar(vector<int> v, int t, int val);

int main() {

    int tamanho;
    cout << "Informe o tamanho do vetor: ";
    cin >> tamanho;

    vector<int> vetor;

    construir(vetor, tamanho);
    ordenar(vetor, tamanho);

    int val;
    cout << "Informe qual valor deve ser buscado: ";
    cin >> val;
    
    buscar(vetor, tamanho, val);

    return 0;
}

void buscar(vector<int> v, int t, int val) {
    int p = t / 2;

    while (v[p] != val) {
        if (val > v[p]) {
            p++;
            p = p + (t - p) / 2;
        } else {
            p--;
            p = p / 2;
        }
    }

    cout << "Valor " << val << " encontrado na posição " << p << endl;
}

void construir(vector<int> &v, int t) {

    int aux;
    for (int i = 0; i < t; i++) {
        cout << "Digite um valor para a posição " << i << ": ";
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
