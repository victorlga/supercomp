#include <iostream>
#include <vector>

using namespace std;

int main() {

    const int linhas = 3;
    const int colunas = 3;

    // definir uma matriz de zeros
    vector<vector<int>> m1(linhas, vector<int>(colunas, 0));

    // imprimir a matriz

    for (const auto &l : m1) {
        for (int num : l) {
            cout << num << " ";
        }
        cout << endl;
    }
}