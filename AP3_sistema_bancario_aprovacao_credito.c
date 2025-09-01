#include <stdio.h>
#include <stdbool.h>

int main() {
    // Variáveis para armazenar as informações do cliente
    float renda_mensal, valor_emprestimo, valor_entrada;
    char historico_credito;
    bool estabilidade_emprego;

    // Solicita as informações financeiras do cliente
    printf("--- Sistema de Aprovacao de Emprestimos ---\n");
    printf("Por favor, forneca as seguintes informacoes:\n");

    printf("Renda mensal: ");
    scanf("%f", &renda_mensal);

    printf("Valor do emprestimo desejado: ");
    scanf("%f", &valor_emprestimo);

    printf("Valor da entrada: ");
    scanf("%f", &valor_entrada);

    printf("Historico de credito (B para bom, R para ruim): ");
    scanf(" %c", &historico_credito);

    printf("Estabilidade no emprego (1 para estavel, 0 para instavel): ");
    int estabilidade_temp;
    scanf("%d", &estabilidade_temp);
    estabilidade_emprego = estabilidade_temp;

    // Implementa a lógica de aprovação
    bool aprovado = true;
    char* motivo_rejeicao = "";

    if (valor_emprestimo > (renda_mensal * 0.3)) {
        aprovado = false;
        motivo_rejeicao = "O valor do emprestimo excede 30% da renda mensal.";
    } else if (historico_credito == 'R' || historico_credito == 'r') {
        aprovado = false;
        motivo_rejeicao = "Historico de credito ruim.";
    } else if (!estabilidade_emprego) {
        aprovado = false;
        motivo_rejeicao = "Cliente com instabilidade no emprego.";
    }

    // Exibe o resultado da análise
    printf("\n--- Resultado da Analise ---\n");
    if (aprovado) {
        printf("Parabens! Seu emprestimo foi aprovado.\n");
    } else {
        printf("Seu emprestimo foi rejeitado.\n");
        printf("Motivo: %s\n", motivo_rejeicao);
    }

    return 0;
}