/* Implementação de hashing perfeito - Inserção e cálculo de desempenho a partir da média de acessos para um dado grupo de chaves inseridas*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream> 

using namespace std;

//Função para criação da tabela do nível 1
vector<vector<int>> criar_tabela_nivel_um(int quantidade_de_registros){
    vector<vector<int>> tabela_nivel_um(quantidade_de_registros);
    return tabela_nivel_um;
}

//Função para criação da tabela do nível 2
vector<vector<int>> criar_tabela_nivel_dois(int quantidade_de_registros){
    vector<vector<int>> tabela_nivel_dois(quantidade_de_registros);
    return tabela_nivel_dois;
}

// Função para gerar as variáveis a e b, de forma aleatória. Estas irão compôr a função de hash
void gerar_variaveis_aleatorias(int &a, int &b) {
    srand(time(NULL));
    a = rand() % 101;
    b = rand() % 101;
}

// Função de inserção 
void insere(vector<vector<int>>& nivel_um, vector<vector<int>>& nivel_dois, int quantidade_de_registros, int a, int b, int& total_acessos,int& total_chaves_inseridas) {
    vector<int> chaves; // Um vetor de chaves, auxiliar, é usado para armazenar as chaves, passadas na entrada, que serão inseridas nos registros
    int chave;
    cin >> chave;

    while (chave != 0) { // armazenando as chaves fornecidas na entrada em um vetor de chaves (auxiliar)
        chaves.push_back(chave);
        cin >> chave;
    }
    
    // a função de hash é dada por: h = ((a * chave + b) mod 101) mod quantidade de registros. 101 é o maior primo, definido por convenção

    // Caso não haja choque de chaves - inserção na tabela principal
    for (int i = 0; i < chaves.size(); i++) {
        int h = ((a * chaves[i] + b) % 101) % quantidade_de_registros; // cálculo do hash
        nivel_um[h].resize(nivel_um[h].size() + 1, chaves[i]); // insere a chave no nível um
        total_acessos++; // incrementa o total de acessos
        total_chaves_inseridas++; // incrementa o total de chaves inseridas
    }

    // Caso  haja choque de chaves - inserção nas tabelas secundárias
    for (int i = 0; i < quantidade_de_registros; i++) {
        int n = nivel_um[i].size();
        if (n > 1) {
            nivel_dois[i].resize(n*n, -1); // nível dois de cada posição tem o tamanho do número de chaves que chocaram no nivel um, elevedo ao quadrado
            for (int j = 0; j < n; j++) {
                int h = ((a * nivel_um[i][j] + b) % 101) % (n*n); // cálculo do hash
                if (nivel_dois[i][h] == -1) {
                    nivel_dois[i][h] = nivel_um[i][j];
                } 
                else {
                    int k = h; // variável k, variável auxiliar que recebe o valor de hash
                    do {
                        k = (k + 1) % (n*n); // atualiza o valor de hash até que aja posição buscada disponível
                        total_acessos++; // incrementa o total de acessos
                    } while (nivel_dois[i][k] != -1); // enquanto houver posições disponíveis
                    nivel_dois[i][k] = nivel_um[i][j]; /*insere a chave no nível dois (não incrementa o total de chaves inseridas pois já foi incrementada
                                                         na primeira passada, no nível um)*/
                }
                total_acessos++; // incrementa o total de acessos
            }
        }
    }
}


/*Função para cálculo da média de acessos realizados para a inserção de um dado bloco de chaves
A média de acessos é dada pela divisão entre o total de acessos realizados, para a inserção de todas as chaves, e o 
número de chaves inseridas*/
double calcula_media_acessos(int total_acessos, int total_chaves_inseridas) {
    if(total_chaves_inseridas == 0) return 0;
    return (double) total_acessos / total_chaves_inseridas;
    
}

/* Funçao de saída : mostra tabela com as chaves inseridas em suas respectivas posições (tabelas primária e secundária) e mostra a média
 de acessos feitos para realizar essas inserções*/
void saida(vector<vector<int>>& nivel_um, vector<vector<int>>& nivel_dois, int quantidade_de_registros, int a, int b, int total_acessos, int total_chaves_inseridas) {
    cout << "Nivel um - principal:" << endl;
    for (int i = 0; i < quantidade_de_registros; i++) {
        cout << "Posicao " << i << ": ";
        if (nivel_um[i].empty()) {
            cout << "registro vazio" << endl;
        } else {
            for (int j = 0; j < nivel_um[i].size(); j++) {
                cout << nivel_um[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    for (int i = 0; i < quantidade_de_registros; i++) {
        
        if (nivel_um[i].size() > 1) {
            cout << "Nivel Dois - secundario:" << endl;
            cout << "posicao " << i << ":" << endl;
            for (int j = 0; j < nivel_dois[i].size(); j++) {
                if (nivel_dois[i].size() > 1){
                    if (nivel_dois[i][j] == -1) {
                        cout << j << ": registro vazio" << endl;
                    } 
                    else {
                        cout << j << ": " << nivel_dois[i][j] << endl;
                    }
                }                
            }
        }

    }
    cout <<  endl;
    double media_acessos = calcula_media_acessos(total_acessos, total_chaves_inseridas); // chama função pra calcular a média de acessos
    cout << endl;
    cout << "Media de acessos: " << media_acessos << endl;
}

/* Entrada:
1ª linha: número de registros
2ª linha: valor das chaves digitas em sequência separadas por um espaço

- A inserção para ao digitar o valor 0 (zero)
*/

int main() {
    int quantidade_de_registros;
    cin >> quantidade_de_registros;

    int total_chaves_inseridas = 0, total_acessos = 0;

    vector<vector<int>> nivel_um = criar_tabela_nivel_um(quantidade_de_registros); // chama a função para criar a tabela do primeiro nível
    vector<vector<int>> nivel_dois = criar_tabela_nivel_dois(quantidade_de_registros); // chama a função para criar a tabela do segundo nível
    
    int a, b;
    gerar_variaveis_aleatorias(a, b); // chama função para geração de variáveis aleatórias
    
    insere(nivel_um, nivel_dois, quantidade_de_registros, a, b, total_acessos, total_chaves_inseridas); // chama função para inserção das chaves 

    // abrir um arquivo de texto para escrever as saídas
    ofstream arquivo_saida("saida.txt");

    // redirecionar a saída padrão (stdout) para o arquivo de texto
    streambuf* backup = cout.rdbuf();
    cout.rdbuf(arquivo_saida.rdbuf());
    
    saida(nivel_um, nivel_dois, quantidade_de_registros, a, b, total_acessos, total_chaves_inseridas); // chama função para produzir a saída

    return 0;
}