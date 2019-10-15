/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaOrdenada.h
 * Author: root
 *
 * Created on 17 de setembro de 2019, 13:53
 */

#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    typedef struct {
        int chave;
    } ObjetoLista;

    typedef struct NoLista *PtrNoLista;

    typedef struct NoLista {
        ObjetoLista elemento;
        PtrNoLista proximo;
    } NoLista;

    typedef struct {
        PtrNoLista primeiro;
        int tamanho;
    } Lista;

    void iniciaLista(Lista *list) {
        list->primeiro = NULL;
        list->tamanho = 0;
    }

    void inserirL(Lista *list, ObjetoLista x) {

        PtrNoLista novo;
        novo = (PtrNoLista) malloc(sizeof (NoLista));
        novo->elemento.chave = x.chave;
        if (list->tamanho == 0 || x.chave < list->primeiro->elemento.chave) {
            novo->proximo = list->primeiro;
            list->primeiro = novo;
            list->tamanho++;
        } else {
            PtrNoLista aux;
            aux = list->primeiro;
            while (aux->proximo != NULL && x.chave > aux->proximo->elemento.chave) {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
            list->tamanho++;
        }
    }

    void imprimirLista(Lista *list) {
        PtrNoLista aux;
        printf("\n[");
        for (aux = list->primeiro; aux != NULL; aux = aux->proximo) {
            printf(" %i ", aux->elemento.chave);
        }
        printf("]\n");
    }

    void destruir(Lista *list) {
        PtrNoLista aux;
        while (aux != NULL) {
            aux = list->primeiro;
            list->primeiro = list->primeiro->proximo;
            free(aux);
        }
    }

    bool estaVaziaL(Lista *list) {
        return (list->tamanho == 0);
    }

    bool pesquisar(Lista *list, ObjetoLista x) {
        if (estaVaziaL(list)) {
            return false;
        }
        PtrNoLista aux = list->primeiro;
        while (aux != NULL && x.chave > aux->elemento.chave) {
            aux = aux->proximo;
        }
        if (aux == NULL || aux->elemento.chave > x.chave) {
            return false;
        } else {
            return true;
        }
    }

    int tamanhoLista(Lista *list) {
        return (list->tamanho);
    }

    void removePrimeiro(Lista *list, ObjetoLista *item) {

        PtrNoLista aux;
        if (!estaVaziaL(list)) {
            aux = list->primeiro;
            item->chave = aux->elemento.chave;
            list->primeiro = list->primeiro->proximo;
            free(aux);
            list->tamanho--;
            
        } //caso 3
    }

    void removeElemento(Lista *list, int chave, ObjetoLista *item) {
        //casos 1 e 2
        if (estaVaziaL(list) || chave < list->primeiro->elemento.chave) {
            printf("Lista vazia ou não existe o elemento na lista\n");
            return;
        } else{
            //se for o primeiro elemento
            if(chave == list->primeiro->elemento.chave){
                printf("Removendo o primeiro elemento!\n");
                removePrimeiro(list, item);
            } else{
                PtrNoLista aux = list->primeiro;
                while((aux->proximo != NULL) && (chave > aux->proximo->elemento.chave)){
                    aux = aux->proximo;
                }
                if((aux->proximo == NULL) || (chave < aux->proximo->elemento.chave)){
                    printf("O elemento não existe na lista!\n");
                } else{
                    PtrNoLista remove = aux->proximo;
                    aux->proximo = aux->proximo->proximo;
                    list->tamanho--;
                    free(remove);
                }
            }
        }
    }

    ObjetoLista primeiroL(Lista *list) {
        return (list->primeiro->elemento);
    }

    ObjetoLista ultimoL(Lista *list) {
        ObjetoLista x;
        PtrNoLista aux = list->primeiro;
        while (aux != NULL && x.chave > aux->elemento.chave) {
            aux = aux->proximo;
            if (list->primeiro->proximo->elemento.chave < x.chave && list->primeiro->proximo == NULL) {
                return x;
            }
        }
    }



#ifdef __cplusplus
}
#endif

#endif /* LISTAORDENADA_H */

