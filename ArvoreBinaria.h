//
// Created by nava on 05/11/24.
//

#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

// constantes
struct no {
    struct no *esquerda;
    int dado;
    struct no *direita;
};

// variáveis
extern struct no *inicio;
extern struct no *anterior;

// protótipos
void inicializar();
void finalizar(struct no *quem);
struct no *novoNo(int dado);
void adicionar(struct no *quem, struct no *aonde);
struct no *localizar(int dado, struct no *aonde);
void excluir(int dado);

#endif //ARVOREBINARIA_H
