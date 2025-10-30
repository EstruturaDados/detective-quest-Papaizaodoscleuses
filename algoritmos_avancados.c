#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

Sala* criarSala(char nome[]) {
    Sala* nova = (Sala*)malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esquerda = nova->direita = NULL;
    return nova;
}

void explorar(Sala* atual) {
    char escolha;
    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);
        printf("Escolha seu caminho:\n");
        printf("(e) Ir para a esquerda\n");
        printf("(d) Ir para a direita\n");
        printf("(s) Sair da exploração\n");
        printf("→ ");
        scanf(" %c", &escolha);

        if (escolha == 's') {
            printf("Exploração encerrada.\n");
            break;
        } else if (escolha == 'e') {
            if (atual->esquerda != NULL)
                atual = atual->esquerda;
            else {
                printf("Você chegou ao fim do caminho à esquerda!\n");
                break;
            }
        } else if (escolha == 'd') {
            if (atual->direita != NULL)
                atual = atual->direita;
            else {
                printf("Você chegou ao fim do caminho à direita!\n");
                break;
            }
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

int main() {
    // Criação das salas (árvore binária)
    Sala* hall = criarSala("Hall de Entrada");
    Sala* salaJantar = criarSala("Sala de Jantar");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    Sala* jardim = criarSala("Jardim");
    Sala* escritorio = criarSala("Escritório");

    // Estrutura da mansão (ligações)
    hall->esquerda = salaJantar;
    hall->direita = biblioteca;
    salaJantar->esquerda = cozinha;
    salaJantar->direita = jardim;
    biblioteca->direita = escritorio;

    printf("=== Detective Quest: Mansão Misteriosa ===\n");
    explorar(hall);

    return 0;
}
