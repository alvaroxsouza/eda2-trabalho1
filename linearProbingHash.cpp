/* Implementação de hashing com encadeamento linear - 
    Inserção e cálculo de desempenho a partir da média de acessos para um dado grupo de chaves inseridas*/

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream> 

using namespace std;

// Função de hash 1 (h1 = Chave mod Número de registros)
int hash1(int chave, int tamanho_arquivo) {
    return chave % tamanho_arquivo;
}

// Função de criação da tabela hash
vector<int> criar_tabela_hash(int tamanho_arquivo){
    int posicao_vazia = -1;
    vector<int> tabela_hash(tamanho_arquivo, posicao_vazia);
    return tabela_hash;
}

// Função para inserção das chaves usando hashing com encadeamento linear
void insere(vector<int>& tabela_hash, int tamanho_arquivo, int& total_chaves_inseridas, int& total_acessos) {
    int chave; 
    while(total_chaves_inseridas < tamanho_arquivo) { // se o total de chaves alcançar o número de registros disponíveis encerra o loop
        cout << "valor da chave: ";
        cin >> chave;

        if(chave == 0) break; //se chave for 0, saia do loop

        int h1 = hash1(chave, tamanho_arquivo); // chamada para calcular o h1

        if (tabela_hash[h1] == -1) { // caso em que, usando h1, a posição calculada está disponível
            tabela_hash[h1] = chave; // chave inserida 
            total_chaves_inseridas++; // incrementa o total de chaves inseridas
            total_acessos++; // incrementa o total de acessos
        } 
        
        else { // caso em que, usando h1, a posição calculada está ocupada
            int i = 1;
            int nova_posicao = (h1 + i) % tamanho_arquivo;
            total_acessos++; // incrementa o total de acessos

            while(tabela_hash[nova_posicao] != -1) { /* o programa continua até que encontre uma posição que esteja disponível, 
                                                atualizando a posição e o número de acessos que vão sendo feitos*/
                i++;
                nova_posicao = (h1 + i) % tamanho_arquivo;
                total_acessos++; // incrementa o total de acessos

            }

            tabela_hash[nova_posicao] = chave; // chave inserida
            total_chaves_inseridas++; // incrementa o total de chaves inseridas
            total_acessos++; // incrementa o total de acessos
        }
    }
}

// Função para cálculo da média de acessos realizados para a inserção de um dado bloco de chaves
double calcula_media_acessos(int total_acessos, int total_chaves_inseridas) {
    if(total_chaves_inseridas == 0) return 0;
    return (double) total_acessos / total_chaves_inseridas;
    
}

/* Funçao de saída : mostra tabela com as chaves inseridas em suas respectivas posições e mostra a média de acessos feitos para
realizar essas inserções*/ 
void saida(vector<int>& tabela_hash, int tamanho_arquivo, int total_acessos, int total_chaves_inseridas) {
    cout << endl;
    cout << "############### Tabela de registros ############### " << endl;
    for (int i = 0; i < tamanho_arquivo; i++) {
        if (tabela_hash[i] == -1) {
            cout << "Registro " << i << ": Registro Vazio" << endl;
        }
        else {
            cout << "Registro " << i << ": " << tabela_hash[i] << endl;
        }
    }
    double media_acessos = calcula_media_acessos(total_acessos, total_chaves_inseridas); // chama função pra calcular a média de acessos
    cout << endl;
    cout << "Media de acessos: " << media_acessos << endl;
}


int main() {
    int tamanho_arquivo = 0, total_chaves_inseridas = 0, total_acessos = 0;
    
    cout << "Numero de registros: ";
    cin >> tamanho_arquivo;
    
    vector<int> tabela_hash = criar_tabela_hash(tamanho_arquivo);

    insere(tabela_hash, tamanho_arquivo, total_chaves_inseridas, total_acessos); // chama função para inserção

    // abrir um arquivo de texto para escrever as saídas
    ofstream arquivo_saida("saida.txt");

    // redirecionar a saída padrão (stdout) para o arquivo de texto
    streambuf* backup = cout.rdbuf();
    cout.rdbuf(arquivo_saida.rdbuf());

    saida(tabela_hash, tamanho_arquivo, total_acessos, total_chaves_inseridas);
    
    return 0;
}
