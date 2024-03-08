#include <iostream>
#include <vector>
using namespace std;

int main() {

    int tamanho;
    cin >> tamanho;

    vector<int> v;
    int num;
    for (int i=0; i<tamanho; i++) {
        cin >> num;
        v.push_back(num);
    }

    int maior = v[0];
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
        if (maior < v[i]) {
            maior = v[i];
        }
    }

    cout << endl;

    cout << "O maior número é " << maior << endl;

    

    return 0;
}