#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void construir(vector<int> &v, int t);
void imprimir(vector<int> v);
void imprimir2(vector<int> v);
void salva_arquivo(vector<int> v);

int main() {

    int tamanho;
    cout << "informe o tamnho do vetor: ";
    cin >> tamanho;

    vector<int> vetor;

    construir(vetor, tamanho);
    imprimir(vetor);
    cout << endl;
    imprimir2(vetor);

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

void imprimir(vector<int> v) {

    cout << "Valores do vetor: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void imprimir2(vector<int> v) {

    cout << "Valores do vetor: ";

    for (int num : v) {
        cout << num << " ";
    }

    cout << "\n";
}

void salva_arquivo(vector<int> v) {

    string file_name = "input_vector.txt";
    ofstream file(file_name);
}