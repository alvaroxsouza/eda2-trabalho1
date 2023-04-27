#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

int main() {
    // Definir o tamanho da tabela hash e a quantidade de entradas
    int tamanhoTabela =  1000000000;
    int quantidadeEntradas = 1000000000;
    
    // Criar lista de números aleatórios
    vector<int> numeros;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100000000);
    for (int i = 0; i < quantidadeEntradas; i++) {
        numeros.push_back(dis(gen));
    }
    
    // Escrever para o arquivo
    ofstream arquivo("entradaGerada.txt");
    if (arquivo.is_open()) {
        // Escrever o tamanho da tabela na primeira linha
        arquivo << tamanhoTabela << endl;
        
        // Escrever a quantidade de entradas na segunda linha
        arquivo << quantidadeEntradas << endl;
        
        // Escrever os números aleatórios nas linhas restantes
        for (int numero : numeros) {
            arquivo << numero << endl;
        }
        
        arquivo.close();
        cout << "Arquivo criado com sucesso!" << endl;
    } else {
        cout << "Não foi possível criar o arquivo.\n" << endl;
    }
    
    return 0;
}