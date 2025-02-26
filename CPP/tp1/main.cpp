#include <iostream>
#include "racional.hpp"  // Verifique se as funções e estruturas estão bem definidas neste arquivo

using namespace std;

int main() {
    int max, n;
    struct racional r1, r2;
    struct racional r_soma, r_subtracao, r_multiplicacao, r_divisao;

    // Lê n e valida
    do {
        cin >> n;
    } while (n <= 0 || n >= 100);

    // Lê max e valida
    do {
        cin >> max;
    } while (max <= 0 || max >= 100);  // Corrigido 'man' para 'max'

    srand(0);

    // Loop para realizar operações com os números racionais
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";  // Corrigido a falta de '<<' no cout
        r1 = sorteia_r(-max, max);
        r2 = sorteia_r(-max, max);

        imprime_r(r1);
        imprime_r(r2);

        if ((!valido_r(r1) || !valido_r(r2))) {
            cout << "NÚMERO INVÁLIDO" << endl;
            return 1;  // Encerra o programa em caso de número inválido
        }

        // Realiza as operações
        r_soma = soma_r(r1, r2);
        r_subtracao = subtrai_r(r1, r2);
        r_multiplicacao = multiplica_r(r1, r2);
        r_divisao = divide_r(r1, r2);

        // Se a divisão for inválida, imprime mensagem de erro
        if (!valido_r(r_divisao)) {
            cout << "DIVISAO INVALIDA" << endl;
            return 1;  // Encerra o programa em caso de divisão inválida
        }

        // Imprime os resultados das operações
        imprime_r(r_soma);
        imprime_r(r_subtracao);
        imprime_r(r_multiplicacao);
        imprime_r(r_divisao);

        cout << endl;  // Adiciona uma linha em branco após cada iteração
    }

    return 0;
}