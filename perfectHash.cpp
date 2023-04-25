#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


vector<vector<int>> criar_tabela_nivel_um(int quantidade_de_registros){
    vector<vector<int>> tabela_nivel_um(quantidade_de_registros);
    return tabela_nivel_um;
}


vector<vector<int>> criar_tabela_nivel_dois(int quantidade_de_registros){
    vector<vector<int>> tabela_nivel_dois(quantidade_de_registros);
    return tabela_nivel_dois;
}

void gerar_variaveis_aleatorias(int &a, int &b) {
    srand(time(NULL));
    a = rand() % 101;
    b = rand() % 101;
}

void insere(vector<int>& chaves, vector<vector<int>>& nivel_um, vector<vector<int>>& nivel_dois, int quantidade_de_registros, int a, int b) {
    // inserção na tabela principal
    for (int i = 0; i < chaves.size(); i++) {
        int h = ((a * chaves[i] + b) % 101) % quantidade_de_registros;
        nivel_um[h].push_back(chaves[i]);
    }

    // inserção nas tabelas secundárias
    for (int i = 0; i < quantidade_de_registros; i++) {
        int n = nivel_um[i].size();
        if (n > 1) {
            nivel_dois[i].resize(n*n, -1);
            for (int j = 0; j < n; j++) {
                int h = ((a * nivel_um[i][j] + b) % 101) % (n*n);
                if (nivel_dois[i][h] == -1) {
                    nivel_dois[i][h] = nivel_um[i][j];
                } else {
                    int k = h;
                    do {
                        k = (k + 1) % (n*n);
                    } while (nivel_dois[i][k] != -1);
                    nivel_dois[i][k] = nivel_um[i][j];
                }
            }
        }
    }
}

void saida(vector<vector<int>>& nivel_um, vector<vector<int>>& nivel_dois, int quantidade_de_registros, int a, int b) {
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
}

int main() {
    vector<int> chaves = { 54, 26, 93, 17, 77, 31 };

    int quantidade_de_registros = 9;

    vector<vector<int>> nivel_um = criar_tabela_nivel_um(quantidade_de_registros);
    vector<vector<int>> nivel_dois = criar_tabela_nivel_dois(quantidade_de_registros);
    
    int a, b;
    gerar_variaveis_aleatorias(a, b);
    
    insere(chaves, nivel_um, nivel_dois, quantidade_de_registros, a, b);
    saida(nivel_um, nivel_dois, quantidade_de_registros, a, b);

    return 0;
}
