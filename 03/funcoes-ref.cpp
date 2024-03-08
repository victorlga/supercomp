#include <iostream>

using namespace std;

int quadrado(int &n);

int main() {

    int t = 10;
    cout << quadrado(t) << endl;
    cout << "valor de t = " << t << endl;

    return 0;
}

int quadrado(int &n) {
    n = n * n;
    return n;
}