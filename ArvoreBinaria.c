//
// Created by nava on 05/11/24.
//
#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinaria.h"

// variáveis
struct no *inicio;
struct no *anterior;

// funções
void inicializar() {
    inicio = NULL;
}

void finalizar(struct no *quem) {
    if(inicio == NULL) {
        return;
    }

    if(quem->esquerda != NULL) {
        printf("indo para esquerda de %d\n", quem->dado);
        finalizar(quem->esquerda);
    }

    if(quem->direita != NULL) {
        printf("indo para direita de %d\n", quem->dado);
        finalizar(quem->direita);
    }

    printf("excluindo %d\n", quem->dado);
    free(quem);
}

struct no * novoNo(int dado) {
    struct no *p = malloc(sizeof(struct no));
    if(!p) {
        printf("Erro de alocaocao de memoria!\n");
        exit(EXIT_FAILURE);
    }

    p->esquerda = NULL;
    p->dado = dado;
    p->direita = NULL;

    return p;
}

void adicionar(struct no *quem, struct no *aonde) {
    if(inicio == NULL) {
        printf("adicionando %d no inicio\n", quem->dado);
        inicio = quem;
    } else {
        if(quem->dado > aonde->dado) {
            // direita
            if(aonde->direita == NULL) {
                printf("adicionando %d a direita de %d\n", quem->dado, aonde->dado);
                aonde->direita = quem;
            }
            else {
                printf("indo para a direita de %d\n", aonde->dado);
                adicionar(quem, aonde->direita);
            }
        }
        else {
            // esquerda
            if(aonde->esquerda == NULL) {
                printf("adicionando %d a esquerda de %d\n", quem->dado, aonde->dado);
                aonde->esquerda = quem;
            }
            else {
                printf("indo para a esquerda de %d\n", aonde->dado);
                adicionar(quem, aonde->esquerda);
            }
        }
    }
}

struct no *localizar(int dado, struct no *aonde) {
    if(inicio == NULL) {
        return NULL;
    }
    if(dado == aonde->dado) {
        return aonde;
    }
    else {
        if(dado > aonde->dado) {
            if(aonde->direita == NULL) {
                return NULL;
            }
            else {
                anterior = aonde;
                printf("indo para a direita de %d\n", aonde->dado);
                return localizar(dado, aonde->direita);
            }
        }
        else {
            if(aonde->esquerda == NULL) {
                return NULL;
            }
            else {
                anterior = aonde;
                printf("indo para a esquerda de %d\n", aonde->dado);
                return localizar(dado, aonde->esquerda);
            }
        }
    }
}

void excluir(int dado) {
    if(inicio == NULL) {
        return;
    }
    struct no *aux = localizar(dado, inicio);
    if(aux == NULL) {
        return;
    }

    if(aux == inicio) {
        inicio = NULL;
    }
    else {
        if(dado > anterior->dado) {
            anterior->direita = NULL;
        }
        else {
            anterior->esquerda = NULL;
        }
    }

    if(aux->esquerda != NULL) {
        adicionar(aux->esquerda, inicio);
    }
    if(aux->direita != NULL) {
        adicionar(aux->direita, inicio);
    }

    free(aux);
}
