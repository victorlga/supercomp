#include <fstream> // biblioteca de manipulação de arquivos
#include <iostream>

using namespace std;

int main() {

    // nome do arquivo
    string nome_arq = "exemplo.txt";

    // abrindo o arquivo para escrita
    ofstream arquivo(nome_arq);
    // verificar se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    // escrita no arquivo
    arquivo << "OL, está é a primeira linha do arquivo" << endl;
    arquivo << "ESta é otura linha, terminando com \n";
    arquivo << "\toi" << endl;

    // fechando o arquivo
    arquivo.close();

    cout << "Arquivo escrito com sucesso !" << endl;

    //  abrindo o arquivo para leitura
    ifstream arq(nome_arq);
    if (!arq.is_open()) {
        cerr << "Erro na abertura do arquivo ..." << endl;
    }

    // lendo e exibindo o conteudo do arquivo
    string linha;
    while (getline(arq, linha)) {
        cout << linha << endl;
    }

    arq.close();

    return 0;
}