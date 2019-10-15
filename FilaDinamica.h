/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FilaDinamica.h
 * Author: root
 *
 * Created on 15 de outubro de 2019, 16:18
 */

#ifndef FILADINAMICA_H
#define FILADINAMICA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    typedef struct {
        int key;
    } objetoFila;

    typedef struct NoFila *ptrNoFila;

    typedef struct NoFila {
        objetoFila obj;
        ptrNoFila proximo;
    } NoFila;

    typedef struct {
        ptrNoFila inicio;
        ptrNoFila fim;
        int contador;
    } filaDin;

    void iniciaFilaDin(filaDin *fila) {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->contador = 0;
    }

    void tamanho(filaDin *fila) {
        printf("Tamanho da fila: %i", fila->contador);
    }

    bool estaVaziaF(filaDin *fila) {
        if (fila->contador == 0) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(filaDin *fila, objetoFila obj) {
        ptrNoFila aux;
        aux = (ptrNoFila) malloc(sizeof (NoFila));

        if (fila->contador == 0) {
            fila->inicio = aux;
            fila->fim = aux;
            aux->proximo = NULL;
            fila->contador += fila->contador;
        } else {
            aux->proximo = NULL;
            fila->fim->proximo = aux;
            fila->fim = fila->fim->proximo;
        }
    }

    objetoFila dequeue(filaDin *fila, objetoFila obj) {
        ptrNoFila aux;
        if (!estaVaziaF(fila)) {
            aux = fila->inicio;
            obj = aux->obj;
            fila->inicio = fila->inicio->proximo;
            free(aux);
            fila->contador -= fila->contador;
            return obj;
        }
    }

    objetoFila primeiroF(filaDin *fila) {
        return fila->inicio->obj;
    }

    objetoFila ultimoF(filaDin *fila) {
        return fila->fim->obj;
    }

    void print(filaDin *fila) {
        ptrNoFila aux;
        printf("[");
        for (aux = fila->inicio; aux != NULL; aux = aux->proximo) {
            printf(" %i ", aux->obj.key);
        }
        printf("]");
    }

    /*void destruir(filaDin *fila) {
        ptrNoFila aux;
        for (aux = fila->inicio; aux != NULL; aux = aux->proximo) {
            free(aux);
        }
    }*/


#ifdef __cplusplus
}
#endif

#endif /* FILADINAMICA_H */

