
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Passo 1: Definição da estrutura de dados
typedef struct {
    char nome[100];
    float media_disciplina1;
    float media_disciplina2;
    float media_geral;
    int classificacao;
} Aluno;

// Passo 2a: Implementação da função para calcular a média geral
float calcularMediaGeral(float media1, float media2) {
    return (media1 + media2) / 2.0;
}

// Passo 2b: Implementação da função de comparação para ordenação
int compararMedias(const void *a, const void *b) {
    Aluno *alunoA = (Aluno *)a;
    Aluno *alunoB = (Aluno *)b;
    if (alunoA->media_geral < alunoB->media_geral) {
        return 1; // Retorna 1 para indicar que B deve vir antes de A (ordem decrescente)
    }
    if (alunoA->media_geral > alunoB->media_geral) {
        return -1; // Retorna -1 para indicar que A deve vir antes de B
    }
    return 0; // Retorna 0 se as médias forem iguais
}

int main() {
    int num_alunos;

    // Passo 3a: Pedir ao usuário que informe quantos alunos serão registrados
    printf("Quantos alunos serao registrados? ");
    scanf("%d", &num_alunos);
    getchar(); // Limpa o buffer do teclado para remover o '\n' deixado pelo scanf

    // Aloca memória dinamicamente para o array de alunos
    Aluno *turma = (Aluno *)malloc(num_alunos * sizeof(Aluno));
    if (turma == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    float soma_medias_turma = 0;

    // Passo 3b: Loop para solicitar os dados de cada aluno
    for (int i = 0; i < num_alunos; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        
        printf("Nome do aluno: ");
        fgets(turma[i].nome, 100, stdin);
        turma[i].nome[strcspn(turma[i].nome, "\n")] = 0; // Remove o '\n' do final do nome

        printf("Media da disciplina 1: ");
        scanf("%f", &turma[i].media_disciplina1);

        printf("Media da disciplina 2: ");
        scanf("%f", &turma[i].media_disciplina2);
        getchar(); // Limpa o buffer novamente

        // Passo 4a: Calcular a média geral de cada aluno
        turma[i].media_geral = calcularMediaGeral(turma[i].media_disciplina1, turma[i].media_disciplina2);
        soma_medias_turma += turma[i].media_geral;
    }

    // Passo 4b: Ordenar a turma em ordem decrescente de médias
    qsort(turma, num_alunos, sizeof(Aluno), compararMedias);

    // Passo 4c: Atribuir as classificações aos alunos
    for (int i = 0; i < num_alunos; i++) {
        turma[i].classificacao = i + 1;
    }

    // Passo 5: Saída de dados para o arquivo
    FILE *arquivo;
    // Passo 6: Abrir o arquivo
    arquivo = fopen("d:\\GITHUB\\ENGENHARIA_DA_COMPUTACAO\\classificacao_alunos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        free(turma);
        return 1;
    }

    fprintf(arquivo, "--- Classificacao Geral da Turma ---\n\n");

    // Passo 5a: Escrever os dados de cada aluno no arquivo
    for (int i = 0; i < num_alunos; i++) {
        fprintf(arquivo, "------------------------------------\n");
        fprintf(arquivo, "Classificacao: %d lugar\n", turma[i].classificacao);
        fprintf(arquivo, "Nome do Aluno: %s\n", turma[i].nome);
        fprintf(arquivo, "Media Disciplina 1: %.2f\n", turma[i].media_disciplina1);
        fprintf(arquivo, "Media Disciplina 2: %.2f\n", turma[i].media_disciplina2);
        fprintf(arquivo, "Media Geral: %.2f\n", turma[i].media_geral);
    }
    
    fprintf(arquivo, "\n------------------------------------\n");
    // Passo 5b: Calcular e escrever a média geral da turma no arquivo
    float media_geral_turma = soma_medias_turma / num_alunos;
    fprintf(arquivo, "Media Geral da Turma: %.2f\n", media_geral_turma);
    fprintf(arquivo, "------------------------------------\n");

    // Passo 6: Fechar o arquivo
    fclose(arquivo);
    
    // Libera a memória alocada
    free(turma);

    printf("\nDados dos alunos foram calculados e salvos com sucesso no arquivo 'classificacao_alunos.txt'.\n");

    return 0;
}
