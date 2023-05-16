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

/**
 * Função para entrada do tamanho do arquivo.
 *
 * A função solicita ao usuário o tamanho da tabela de registros e retorna o valor informado.
 * O tamanho é lido a partir da entrada padrão utilizando o operador de extração (>>).
 *
 * Retorna:
 *   - O tamanho da tabela de registros informado pelo usuário.
 */
long int entrada_tamanho_do_arquivo() {
    long int tamanho_tabela = 0;
    cin >> tamanho_tabela;
    return tamanho_tabela;
}

/**
 * Inicializa o arquivo para o método de encadeamento explícito.
 *
 * Parâmetros:
 *   - tamanho_tabela: Tamanho da tabela de registros.
 *
 * Retorna:
 *   - Um ponteiro para o arquivo (vetor de nós) inicializado.
 *
 * A função aloca memória para o arquivo utilizado pelo método de encadeamento explícito.
 * Cada posição do arquivo é representada por um nó. A função cria um novo nó para cada posição
 * do arquivo e retorna um ponteiro para o arquivo inicializado.
 */
node* inicializa_arquivo(long int tamanho_tabela) {
    node* arquivo = new node[tamanho_tabela];
    for(long int i = 0; i < tamanho_tabela; i++) {
        new (&arquivo[i]) node();
    }
    return arquivo;
}

/**
 * Cria e retorna uma tabela hash para o método de hashing escolhido.
 *
 * Parâmetros:
 *   - tamanho_arquivo: Tamanho da tabela de registros.
 *
 * Retorna:
 *   - Uma tabela hash inicializada com valores vazios (-1) e com o tamanho especificado.
 *
 * A função cria uma tabela hash a ser utilizada pelo método de hashing escolhido.
 * A tabela é representada como um vetor de long int, onde cada posição corresponde a uma posição
 * da tabela de registros. A função preenche a tabela com valores vazios (-1) e a retorna.
 */
vector<long int> criar_tabela_hash(long int tamanho_arquivo){
    long int posicao_vazia = -1;
    vector<long int> tabela_hash(tamanho_arquivo, posicao_vazia);
    return tabela_hash;
}

/**
 * Cria e retorna uma tabela de nível um para o hash perfeito.
 *
 * Parâmetros:
 *   - tamanho_arquivo: Tamanho da tabela de registros.
 *
 * Retorna:
 *   - Uma tabela de nível um vazia com o tamanho especificado.
 *
 * A função cria uma tabela de nível um para ser utilizada no hash perfeito.
 * A tabela é representada como um vetor de vetores de long int, onde cada posição
 * do vetor principal corresponde a uma posição da tabela de registros do hash perfeito.
 * A função cria essa tabela vazia com o tamanho especificado e a retorna.
 */
vector<vector<long int>> criar_tabela_nivel_um(long int tamanho_arquivo) {
    vector<vector<long int>> tabela_nivel_um(tamanho_arquivo);
    return tabela_nivel_um;
}

/**
 * Cria e retorna uma tabela de nível dois para o hash perfeito.
 *
 * Parâmetros:
 *   - tamanho_arquivo: Tamanho da tabela de registros.
 *
 * Retorna:
 *   - Uma tabela de nível dois vazia com o tamanho especificado.
 *
 * A função cria uma tabela de nível dois para ser utilizada no hash perfeito.
 * A tabela é representada como um vetor de vetores de long int, onde cada posição
 * do vetor principal corresponde a uma posição da tabela de registros do hash perfeito.
 * A função cria essa tabela vazia com o tamanho especificado e a retorna.
 */
vector<vector<long int>> criar_tabela_nivel_dois(long int tamanho_arquivo) {
    vector<vector<long int>> tabela_nivel_dois(tamanho_arquivo);
    return tabela_nivel_dois;
}

/**
 * Gera dois números aleatórios inteiros.
 *
 * Parâmetros:
 *   - a: Referência para a variável onde o primeiro número aleatório será armazenado.
 *   - b: Referência para a variável onde o segundo número aleatório será armazenado.
 *
 * A função utiliza o tempo atual como semente para a geração de números aleatórios.
 * Em seguida, gera dois números inteiros aleatórios entre 0 e 100 (inclusive)
 * e os armazena nas variáveis a e b, respectivamente.
 */
void gerar_numeros_aleatorios(int &a, int &b) {
    srand(time(NULL));
    a = rand() % 101;
    b = rand() % 101;
}

/**
 * Função principal do programa.
 *
 * A função main é responsável pela execução principal do programa. Ela realiza as seguintes etapas:
 *   1. Lê o tamanho do arquivo através da função entrada_tamanho_do_arquivo().
 *   2. Inicializa as variáveis necessárias, como quantidade_chaves, posicao_ponteiro_encadeamento_explicito,
 *      quantidade_acessos_total_HEEAE, quantidade_acessos_total_duplo, quantidade_acessos_total_sondagem_linear,
 *      quantidade_acessos_total_perfeito, total_chaves_inseridas_HEEAE, total_chaves_inseridas_duplo,
 *      total_chaves_inseridas_sondagem, total_chaves_inseridas_perfeito.
 *   3. Inicializa o arquivo_HEEAE através da função inicializa_arquivo() e as tabelas arquivo_duplo_hash e
 *      arquivo_sondagem_linear através da função criar_tabela_hash().
 *   4. Inicia um loop para leitura das chaves a serem inseridas na tabela:
 *      - Lê uma chave através da entrada padrão.
 *      - Chama as funções de inserção hash_encadeamento_explicito::insercao_encadeamento_explicito(),
 *        hash_duplo::insere_duplo_hash() e sondagem_linear_hash::insere_sondagem_linear() para inserir a chave
 *        nas respectivas tabelas, atualizando as contagens e parâmetros relevantes.
 *      - Adiciona a chave ao vetor chaves e incrementa a quantidade_chaves.
 *   5. Gera os números aleatórios a e b através da função gerar_numeros_aleatorios().
 *   6. Cria as tabelas nivel_um e nivel_dois através das funções criar_tabela_nivel_um() e criar_tabela_nivel_dois().
 *   7. Chama a função hash_perfeito::insere_perfeito_hash() para inserir as chaves nas tabelas de hashing perfeito,
 *      atualizando as contagens e parâmetros relevantes.
 *   8. Calcula as médias de acessos por chave para cada método de hashing.
 *   9. Chama as funções de saída hash_encadeamento_explicito::saida_encadeamento_explicito(),
 *      hash_duplo::saida_duplo_hash(), sondagem_linear_hash::saida_sondagem_linear() e
 *      hash_perfeito::saida_perfeito_hash() para exibir as tabelas de registros de cada método de hashing.
 *  10. Chama a função saida::saida_informacoes_gerais_estatisticas() para exibir as informações gerais e estatísticas
 *      do programa.
 *
 * Retorna:
 *   - 0, indicando que o programa foi executado sem erros.
 */
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
    return 0;
}
