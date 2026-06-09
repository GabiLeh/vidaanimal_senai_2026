#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_ANIMAIS 100
struct animal {
    int identificacao;
    char nome[20];
    char raca[20];
    int idade;
    char tsanguineo[2];
    int b;
};
struct animal lista[MAX_ANIMAIS];
int total = 0;
void cadastrar() {
    int op = 1;
    SetConsoleOutputCP(CP_UTF8);
    while (op != 0) {
        if (total >= MAX_ANIMAIS) {
            printf("Limite de cadastros atingido\n");
            break;
        }
        struct animal a;
        a.identificacao = total + 1;
        a.b = 1;
        printf("Cadastro de Animal (ID: %d)\n", a.identificacao);
        printf("Qual o nome do animal? ");
        scanf("%s", a.nome);
        printf("Qual a raça? ");
        scanf("%s", a.raca);
        printf("Idade? ");
        scanf("%d", &a.idade);
        fflush(stdin);
        printf("Tipo sanguíneo? ");
        scanf("%s", a.tsanguineo);
        lista[total] = a;
        total++;
        printf("Animal cadastrado\n");
        printf("Deseja cadastrar outro? (1 - Sim / 0 - Não): ");
        scanf("%d", &op);
    }
}
void consultar() {
    printf("Animais Cadastrados:\n");
    int cadastrados = 0;
    for (int i = 0; i < total; i++) {
        if (lista[i].b == 1) {
            printf("ID: %d\tNome: %s\tRaça: %s\tIdade: %d\tTipo sanguíneo: %s\n", lista[i].identificacao, lista[i].nome, lista[i].raca, lista[i].idade, lista[i].tsanguineo);
            cadastrados++;
        }
    }
    if (cadastrados == 0) {
        printf("Nenhum animal encontrado.\n");
    }
}
void alterar() {
    int id_busca;
    printf("Digite o ID do animal para alterar: ");
    scanf("%d", &id_busca);
    for (int i = 0; i < total; i++) {
        if (lista[i].identificacao == id_busca && lista[i].b == 1) {
            printf("Nome: ");
            scanf("%s", lista[i].nome);
            printf("Raça: ");
            scanf("%s", lista[i].raca);
            printf("Idade? ");
            scanf("%d", &lista[i].idade);
            printf("Tipo sanguíneo? ");
            scanf("%s", lista[i].tsanguineo);
            printf("Dados atualizados\n");
            return;
        }
    }
    printf("Animal com ID %d não encontrado ou excluído.\n", id_busca);
}

void excluir() {
    int idbusca;
    printf("Digite o ID do animal para excluir: ");
    scanf("%d", &idbusca);
    for (int i = 0; i < total; i++) {
        if (lista[i].identificacao == idbusca && lista[i].b == 1) {
            lista[i].b = 0;
            printf("Animal excluído.\n");
            return;
        }
    }
    printf("Animal com ID %d não encontrado.\n", idbusca);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int op = 0;
    do {
        printf("       Clínica Veterinária       \n");
        printf("\n1 - Cadastrar\n2 - Consultar\n3 - Alterar informações\n4 - Excluir informações\n5 - Sair\n");
        printf("O que deseja fazer? ");
        scanf("%d", &op);
        switch (op) {
            case 1: cadastrar(); break;
            case 2: consultar(); break;
            case 3: alterar(); break;
            case 4: excluir(); break;
            case 5: printf("SAINDO...\n"); break;
            default: printf("Opção inválida\n");
        }
    } while (op != 5);
    return 0;
}