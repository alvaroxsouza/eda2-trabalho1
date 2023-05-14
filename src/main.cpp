#include <iostream>
#include <iomanip>

#include "node/node.hpp"
#include "hash/encadeamento_explicito_hash/encadeamento_explicito.hpp"
#include "hash/duplo_hash/duplo_hash.hpp"
#include "hash/sondagem_linear_hash/sondagem_linear.hpp"
#include "hash/perfeito_hash/hash_perfeito.hpp"
#include "saida_programa/saida.hpp"

using namespace std;
using namespace node_class;
using namespace hash_encadeamento_explicito_class;
using namespace hash_perfeito_class;
using namespace hash_duplo_class;
using namespace sondagem_linear_hash_class;
using namespace saida_class;

long int entrada_tamanho_do_arquivo() {
    long int tamanho_tabela = 0;
    cin >> tamanho_tabela;
    return tamanho_tabela;
}

node* inicializa_arquivo(long int tamanho_tabela) {
    node* arquivo = new node[tamanho_tabela];
    for(long int i = 0; i < tamanho_tabela; i++) {
        new (&arquivo[i]) node();
    }
    return arquivo;
}

vector<long int> criar_tabela_hash(long int tamanho_arquivo){
    long int posicao_vazia = -1;
    vector<long int> tabela_hash(tamanho_arquivo, posicao_vazia);
    return tabela_hash;
}

vector<vector<long int>> criar_tabela_nivel_um(long int tamanho_arquivo) {
    vector<vector<long int>> tabela_nivel_um(tamanho_arquivo);
    return tabela_nivel_um;
}

vector<vector<long int>> criar_tabela_nivel_dois(long int tamanho_arquivo) {
    vector<vector<long int>> tabela_nivel_dois(tamanho_arquivo);
    return tabela_nivel_dois;
}

void gerar_numeros_aleatorios(int &a, int &b) {
    srand(time(NULL));
    a = rand() % 101;
    b = rand() % 101;
}

int main() {
    long int tamanho_arquivo = entrada_tamanho_do_arquivo();
    long int quantidade_chaves = 0;

    long int posicao_ponteiro_encadeamento_explicito = tamanho_arquivo - 1;

    long int quantidade_acessos_total_HEEAE = 0;
    long int quantidade_acessos_total_duplo = 0;
    long int quantidade_acessos_total_sondagem_linear = 0;
    long int quantidade_acessos_total_perfeito = 0;
    
    long int total_chaves_inseridas_HEEAE = 0;
    long int total_chaves_inseridas_duplo = 0;
    long int total_chaves_inseridas_sondagem = 0;
    long int total_chaves_inseridas_perfeito = 0;

    node *arquivo_HEEAE = inicializa_arquivo(tamanho_arquivo);
    vector<long int> arquivo_duplo_hash = criar_tabela_hash(tamanho_arquivo);
    vector<long int> arquivo_sondagem_linear = criar_tabela_hash(tamanho_arquivo);
    vector<long int> chaves;

    long int valor_chave;
    while(cin >> valor_chave) {
        hash_encadeamento_explicito::insercao_encadeamento_explicito(
            arquivo_HEEAE,
            valor_chave,
            tamanho_arquivo,
            posicao_ponteiro_encadeamento_explicito,
            total_chaves_inseridas_HEEAE,
            quantidade_acessos_total_HEEAE
            );
        
        hash_duplo::insere_duplo_hash(
            arquivo_duplo_hash,
            valor_chave,
            tamanho_arquivo,
            total_chaves_inseridas_duplo,
            quantidade_acessos_total_duplo
            );
        
        sondagem_linear_hash::insere_sondagem_linear(
            arquivo_sondagem_linear,
            valor_chave,
            tamanho_arquivo,
            total_chaves_inseridas_sondagem,
            quantidade_acessos_total_sondagem_linear
            );

        chaves.push_back(valor_chave);
        quantidade_chaves++;
    }


    int a, b;
    gerar_numeros_aleatorios(a, b);

    vector<vector<long int>> nivel_um = criar_tabela_nivel_um(tamanho_arquivo);
    vector<vector<long int>> nivel_dois = criar_tabela_nivel_dois(tamanho_arquivo);

    hash_perfeito::insere_perfeito_hash(
        nivel_um,
        nivel_dois,
        chaves,
        tamanho_arquivo,
        a, b,
        total_chaves_inseridas_perfeito,
        quantidade_acessos_total_perfeito
        );

    double media_acessos_HEEAE = double(quantidade_acessos_total_HEEAE) / total_chaves_inseridas_HEEAE;
    double media_acessos_duplo = double(quantidade_acessos_total_duplo) / total_chaves_inseridas_duplo;
    double media_acessos_sondagem_linear = double(quantidade_acessos_total_sondagem_linear) / total_chaves_inseridas_sondagem;
    double media_acessos_perfeito = double(quantidade_acessos_total_perfeito) / total_chaves_inseridas_perfeito;

    hash_encadeamento_explicito::saida_encadeamento_explicito(arquivo_HEEAE, tamanho_arquivo);
    hash_duplo::saida_duplo_hash(arquivo_duplo_hash, tamanho_arquivo);
    sondagem_linear_hash::saida_sondagem_linear(arquivo_sondagem_linear, tamanho_arquivo);
    hash_perfeito::saida_perfeito_hash(nivel_um, nivel_dois, tamanho_arquivo);

    saida::saida_informacoes_gerais_estatisticas(
        tamanho_arquivo, quantidade_chaves,
        quantidade_acessos_total_HEEAE, media_acessos_HEEAE,
        quantidade_acessos_total_duplo, media_acessos_duplo,
        quantidade_acessos_total_sondagem_linear, media_acessos_sondagem_linear,
        quantidade_acessos_total_perfeito, media_acessos_perfeito
    );
}
