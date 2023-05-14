
#ifndef SAIDA_HPP
#define SAIDA_HPP

#include <iostream>
#include <iomanip>

using namespace std;

namespace saida_class {
    class saida {
        private:
            static void informacoes_arquivo_final(
                long int tamanho_arquivo,
                long int quantidade_chaves
                );

            static void estatisticas_HEEAE(
                long int quantidade_acessos_total_HEEAE,
                double media_acessos_HEEAE
                );

            static void estatisticas_duplo_hash(
                long int quantidade_acessos_total_duplo,
                double media_acessos_duplo
                );
            static void estatisticas_sondagem_linear(
                long int quantidade_acessos_total_sondagem_linear,
                double media_acessos_sondagem_linear
                );
            static void estatisticas_perfeito_hash(
                long int quantidade_acessos_total_perfeito,
                double media_acessos_perfeito
                );
        public:
            static void saida_informacoes_gerais_estatisticas(
                long int tamanho_arquivo, long int quantidade_chaves,
                long int quantidade_acessos_total_HEEAE, double media_acessos_HEEAE,
                long int quantidade_acessos_total_duplo, double media_acessos_duplo,
                long int quantidade_acessos_total_sondagem_linear, double media_acessos_sondagem_linear,
                long int quantidade_acessos_total_perfeito, double media_acessos_perfeito
            );
    };
}

#endif
