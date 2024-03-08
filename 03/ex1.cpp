#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void construir(vector<int> &v, int t);
void imprimir(vector<int> v);
void imprimir2(vector<int> v);
void salvar_arquivo(vector<int> v);

int main() {

    int tamanho;
    cout << "informe o tamnho do vetor: ";
    cin >> tamanho;

    vector<int> vetor;

    construir(vetor, tamanho);

    salvar_arquivo(vetor);

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


void salvar_arquivo(vector<int> v) {
    string fname = "ex1.txt";

    ofstream ex1(fname);

    if (!ex1.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
    }

    for (int num : v) {
        ex1 << num << " ";
    }

    ex1 << endl;

    ex1.close();

    ifstream rex1(fname);

    if (!rex1.is_open()) {
        cerr << "ERRO" << endl;
    }

    string line;
    while (getline(rex1, line)) {
        cout << line << endl;
    }

}