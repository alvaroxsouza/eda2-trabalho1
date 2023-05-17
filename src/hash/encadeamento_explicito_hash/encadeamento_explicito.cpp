#ifndef HASH_ENCADEAMENTO_EXPLICITO_CPP
#define HASH_ENCADEAMENTO_EXPLICITO_CPP

#include "encadeamento_explicito.hpp"

using namespace hash_encadeamento_explicito_class;

/**
 * Função para buscar a posição inicial de inserção na tabela hash.
 *
 * A função recebe um ponteiro para um array de nós (arquivo),
 * o valor do nó a ser inserido e o tamanho da tabela hash.
 * 
 * Parâmetros:
 *   - arquivo: ponteiro para o array de nós que representa a tabela hash.
 *   - valor_node: valor do nó a ser inserido na tabela hash.
 *   - tamanho_arquivo: tamanho do arquivo/tabela hash.
 * 
 * A função utiliza a função de hash funcao_hash_h1 para calcular a posição inicial de inserção,
 * utilizando o valor do nó e o tamanho da tabela hash como parâmetros.
 * 
 * Retorna a posição inicial de inserção na tabela hash.
 */
int busca_posicao_inicial(node *arquivo,
    long int valor_node,
    long int tamanho_arquivo) {
    int posicao_inicial = hash_funcao::funcao_hash_h1(valor_node, tamanho_arquivo);
    return posicao_inicial;
}

/**
 * Função para encontrar a posição do último nó livre em uma lista encadeada no arquivo.
 *
 * A função recebe um ponteiro para um array de nós (arquivo),
 * a posição do ponteiro de encadeamento explícito,
 * a quantidade total de acessos realizados e a posição inicial de inserção na tabela hash.
 *
 * Parâmetros:
 *   - arquivo: ponteiro para o array de nós que representa a tabela hash.
 *   - posicao_ponteiro_encadeamento_explicito: referência para a variável que guarda a posição do ponteiro de encadeamento explícito.
 *   - quantidade_acessos_total_HEEAE: referência para a variável que guarda a quantidade de acessos totais realizados.
 *   - posicao_inicial_insercao_arquivo: posição inicial de inserção na tabela hash.
 *
 * A função começa na posição inicial de inserção e percorre a lista encadeada até encontrar o último nó livre.
 * Durante o percurso, atualiza a quantidade total de acessos realizados.
 *
 * Retorna a posição do último nó livre na lista encadeada.
 */
int encontrar_ultimo_node_livre_lista_encadeada(node* arquivo,
    long int& posicao_ponteiro_encadeamento_explicito,
    long int& quantidade_acessos_total_HEEAE,
    long int posicao_inicial_insercao_arquivo) {

    long int posicao_atual_tabela = posicao_inicial_insercao_arquivo;
    while (arquivo[posicao_atual_tabela].get_proximo_node() != -1) {
        posicao_atual_tabela = arquivo[posicao_atual_tabela].get_proximo_node();
        quantidade_acessos_total_HEEAE++;
    }
    return posicao_atual_tabela;
}

/**
 * Função para encontrar a primeira posição livre no arquivo (tabela hash).
 *
 * A função recebe um ponteiro para um array de nós (arquivo),
 * a posição do ponteiro de encadeamento explícito e a quantidade total de acessos realizados.
 *
 * Parâmetros:
 *   - arquivo: ponteiro para o array de nós que representa a tabela hash.
 *   - posicao_ponteiro_encadeamento_explicito: referência para a variável que guarda a posição do ponteiro de encadeamento explícito.
 *   - quantidade_acessos_total_HEEAE: referência para a variável que guarda a quantidade de acessos totais realizados.
 *
 * A função executa um loop enquanto a posição do ponteiro de encadeamento explícito for maior ou igual a zero
 * e a posição no arquivo estiver ocupada (indicado pelo método is_esta_ocupado() do nó).
 * Dentro do loop, a função decrementa a posição do ponteiro de encadeamento explícito e incrementa a quantidade de acessos totais.
 *
 * Após a execução da função, a variável posicao_ponteiro_encadeamento_explicito conterá a primeira posição livre no arquivo.
 */
void encontrar_primeiro_registro_livre(node* arquivo, 
    long int& posicao_ponteiro_encadeamento_explicito,
    long int& quantidade_acessos_total_HEEAE) {
    while (posicao_ponteiro_encadeamento_explicito >= 0 
        && arquivo[posicao_ponteiro_encadeamento_explicito].is_esta_ocupado()) {
        posicao_ponteiro_encadeamento_explicito--;
        quantidade_acessos_total_HEEAE++;
    }
}

/**
 * Função para inserir um valor em uma tabela hash utilizando o método de encadeamento explícito.
 *
 * A função recebe um ponteiro para um array de nós (arquivo), o valor do nó a ser inserido,
 * o tamanho da tabela hash, a posição do ponteiro de encadeamento explícito,
 * o total de chaves inseridas usando encadeamento explícito e a quantidade total de acessos realizados.
 *
 * Parâmetros:
 *   - arquivo: ponteiro para o array de nós que representa a tabela hash.
 *   - valor_node: valor do nó a ser inserido na tabela hash.
 *   - tamanho_arquivo: tamanho do arquivo/tabela hash.
 *   - posicao_ponteiro_encadeamento_explicito: referência para a variável que guarda a posição do ponteiro de encadeamento explícito.
 *   - total_chaves_inseridas_HEEAE: referência para a variável que guarda o total de chaves inseridas usando encadeamento explícito.
 *   - quantidade_acessos_total_HEEAE: referência para a variável que guarda a quantidade de acessos totais realizados.
 *
 * A função começa buscando a posição inicial de inserção no arquivo através da função busca_posicao_inicial.
 * Se a posição inicial estiver desocupada, o valor_node é inserido diretamente nessa posição.
 * Caso contrário, é realizado o encadeamento explícito.
 *
 * Primeiro, a função encontra a posição atual na tabela hash onde será inserido o novo nó.
 * Para isso, utiliza a função encontrar_ultimo_node_livre_lista_encadeada.
 * Esta função procura o último nó livre na lista encadeada começando a busca pela posição inicial de inserção.
 *
 * Após encontrar a posição atual, a função encontra a primeira posição livre no arquivo
 * para ser utilizada como próximo nó na lista encadeada.
 * Isso é feito através da função encontrar_primeiro_registro_livre.
 *
 * Se a posição do ponteiro de encadeamento explícito for maior ou igual a zero (ou seja, existe uma posição livre),
 * o novo nó é inserido na posição atual da tabela hash e o próximo nó é definido como o ponteiro de encadeamento explícito.
 * As variáveis de contagem são atualizadas.
 */
void hash_encadeamento_explicito::insercao_encadeamento_explicito(node* arquivo,
    long int valor_node,
    long int tamanho_arquivo,
    long int& posicao_ponteiro_encadeamento_explicito,
    long int& total_chaves_inseridas_HEEAE, 
    long int& quantidade_acessos_total_HEEAE) {
    
    if(total_chaves_inseridas_HEEAE < tamanho_arquivo) {
        long int posicao_inicial_insercao_arquivo =
        busca_posicao_inicial(arquivo, valor_node, tamanho_arquivo);
        if (!arquivo[posicao_inicial_insercao_arquivo].is_esta_ocupado())
        {
            arquivo[posicao_inicial_insercao_arquivo].set_valor_node(valor_node);
            arquivo[posicao_inicial_insercao_arquivo].set_esta_ocupado(true);
            quantidade_acessos_total_HEEAE++;
            total_chaves_inseridas_HEEAE++;
        } else {
            long int posicao_atual_tabela = 
                encontrar_ultimo_node_livre_lista_encadeada(arquivo,
                    posicao_ponteiro_encadeamento_explicito,
                    quantidade_acessos_total_HEEAE,
                    posicao_inicial_insercao_arquivo);
        
            encontrar_primeiro_registro_livre(arquivo, 
                posicao_ponteiro_encadeamento_explicito,
                quantidade_acessos_total_HEEAE
                );

            if (posicao_ponteiro_encadeamento_explicito >= 0) {
                arquivo[posicao_atual_tabela].set_proximo_node(posicao_ponteiro_encadeamento_explicito);
                arquivo[posicao_ponteiro_encadeamento_explicito].set_valor_node(valor_node);
                arquivo[posicao_ponteiro_encadeamento_explicito].set_esta_ocupado(true);
                total_chaves_inseridas_HEEAE++;
                quantidade_acessos_total_HEEAE++;
            }
        }
    } else {
        return;
    }
    
}

#endif
