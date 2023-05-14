#ifndef SAIDA_CPP
#define SAIDA_CPP

#include "saida.hpp"

using namespace saida_class;

void saida::informacoes_arquivo_final(long int tamanho_arquivo,long int quantidade_chaves) {
    cout << "Tamanho do arquivo: " << tamanho_arquivo << endl;
    cout << "Quantidade de chaves: " << quantidade_chaves << endl;
}

void saida::estatisticas_HEEAE(long int quantidade_acessos_total_HEEAE, double media_acessos_HEEAE) {
    cout << "Quantidade de acessos Encadeamento aberto com alocação estática: " 
    << quantidade_acessos_total_HEEAE << endl << fixed << setprecision(1) 
    << "Media de acessos: " << media_acessos_HEEAE << endl;
}

void saida::estatisticas_duplo_hash(long int quantidade_acessos_total_duplo, double media_acessos_duplo) {
    cout << "Quantidade de acessos hashing duplo: " << quantidade_acessos_total_duplo << endl;
    cout << fixed << setprecision(1) << "Media de acessos: " << media_acessos_duplo << endl;
}

void saida::estatisticas_sondagem_linear(long int quantidade_acessos_total_sondagem_linear, double media_acessos_sondagem_linear) {
    cout << "Quantidade de acessos sondagem linear: " << quantidade_acessos_total_sondagem_linear << endl; 
    cout << fixed << setprecision(1) << "Media de acessos: " << media_acessos_sondagem_linear << endl;
}

void saida::estatisticas_perfeito_hash(long int quantidade_acessos_total_perfeito, double media_acessos_perfeito) {
    cout << "Quantidade de acessos hashing perfeito: " << quantidade_acessos_total_perfeito << endl;
    cout << fixed << setprecision(1) << "Media de acessos: " << media_acessos_perfeito << endl;
}

void saida::saida_informacoes_gerais_estatisticas(
    long int tamanho_arquivo,long int quantidade_chaves,
    long int quantidade_acessos_total_HEEAE, double media_acessos_HEEAE,
    long int quantidade_acessos_total_duplo, double media_acessos_duplo,
    long int quantidade_acessos_total_sondagem_linear, double media_acessos_sondagem_linear,
    long int quantidade_acessos_total_perfeito, double media_acessos_perfeito
) {
    informacoes_arquivo_final(
        tamanho_arquivo,
        quantidade_chaves
    );

    estatisticas_HEEAE(
        quantidade_acessos_total_HEEAE,
        media_acessos_HEEAE
    );

    estatisticas_duplo_hash(
        quantidade_acessos_total_duplo,
        media_acessos_duplo
    );
    estatisticas_sondagem_linear(
        quantidade_acessos_total_sondagem_linear,
        media_acessos_sondagem_linear
    );
    estatisticas_perfeito_hash(
        quantidade_acessos_total_perfeito,
        media_acessos_perfeito
    );
}

#endif
