/* Implementação de hashing duplo - Inserção e cálculo de desempenho a partir da média de acessos para um dado grupo de chaves inseridas*/

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream> 

using namespace std;

// Função de hash 1 (h1 = Chave mod Número de registros)
int hash1(int chave, int quantidade_de_registros) {
    return chave % quantidade_de_registros;
}

/*Função de hash 2 (h2 = 1, se a chave for menor que o número de registros e h2 = chão da divisão entre Chave e número de registros
nos demais casos)*/
int hash2(int chave, int quantidade_de_registros) {
    if(chave < quantidade_de_registros){ 
        chave = 1;
    }
    if (chave >= quantidade_de_registros){
        chave = floor (chave / quantidade_de_registros);
    }
    return chave;
}

// Função de criação da tabela hash
vector<int> criar_tabela_hash(int quantidade_de_registros){
    int posicao_vazia = -1;
    vector<int> tabela_hash(quantidade_de_registros, posicao_vazia);
    return tabela_hash;
}

// Função para inserção das chaves usando hashing duplo
void insere(vector<int>& tabela_hash, int quantidade_de_registros, int& total_chaves_inseridas, int& total_acessos) {
    int chave; 
    while(total_chaves_inseridas < quantidade_de_registros) { // se o total de chaves alcançar o número de registros disponíveis encerra o loop
        cout << "valor da chave: ";
        cin >> chave;

        if(chave == 0) break; //se chave for 0, saia do loop

        int h1 = hash1(chave, quantidade_de_registros); // chamada para calcular o h1
        int h2 = hash2(chave, quantidade_de_registros); // chamada para calcular o h2

        if (tabela_hash[h1] == -1) { // caso em que, usando h1, a posição calculada está disponível
            tabela_hash[h1] = chave; // chave inserida 
            //cout << "Chave " << chave << " inserida na posicao " << h1 << endl;
            total_chaves_inseridas++; // incrementa o total de chaves inseridas
            total_acessos++; // incrementa o total de acessos
        } 
        
        else { // caso em que, usando h1, a posição calculada está ocupada
            int i = 1;
            int nova_posicao = (h1 + i*h2) % quantidade_de_registros; // calcula a nova posição usando o h2 
            total_acessos++; // incrementa o total de acessos

            while(tabela_hash[nova_posicao] != -1) { /* o programa continua até que encontre uma posição que esteja disponível, 
                                                atualizando a posição e o número de acessos que vão sendo feitos*/
                i++;
                nova_posicao = (h1 + i*h2) % quantidade_de_registros; // calcula a nova posição usando o h2
                total_acessos++; // incrementa o total de acessos

            }

            tabela_hash[nova_posicao] = chave; // chave inserida
            //cout << "Chave " << chave << " inserida na posicao " << nova_posicao << endl;
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
void saida(vector<int>& tabela_hash, int quantidade_de_registros, int total_acessos, int total_chaves_inseridas) {
    cout << endl;
    cout << "############### Tabela de registros ############### " << endl;
    for (int i = 0; i < quantidade_de_registros; i++) {
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
    int quantidade_de_registros = 0, total_chaves_inseridas = 0, total_acessos = 0;
    
    cout << "Numero de registros: ";
    cin >> quantidade_de_registros;
    
    vector<int> tabela_hash = criar_tabela_hash(quantidade_de_registros);

    insere(tabela_hash, quantidade_de_registros, total_chaves_inseridas, total_acessos); // chama função para inserção

    // abrir um arquivo de texto para escrever as saídas
    ofstream arquivo_saida("saida.txt");

    // redirecionar a saída padrão (stdout) para o arquivo de texto
    streambuf* backup = cout.rdbuf();
    cout.rdbuf(arquivo_saida.rdbuf());

    saida(tabela_hash, quantidade_de_registros, total_acessos, total_chaves_inseridas);
    
    return 0;
}
