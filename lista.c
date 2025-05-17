#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista *criaLista(char chave){
    Lista *lista = malloc(sizeof(Lista));
    if (lista == NULL){
        printf("erro ao alocar memoria\n");
        exit(1);
    }
    lista->chave = chave;
    lista->tamanho = 0;
    lista->inicial = NULL;
    return lista;
}

void insereValor(Lista *lista, int valor){
    lista->tamanho++;
    Node *node = malloc(sizeof(Node));
    if (node == NULL){
        printf("erro ao alocar memoria\n");
        exit(1);
    }
    node->valor = valor;
    node->proximo = NULL;
    if (lista->inicial == NULL){
        lista->inicial = node;
    }
    else{
        Node *aux = lista->inicial;
        while (aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = node;
    }
}

void liberaLista(Lista *lista){ 
    Node *aux = lista->inicial; 
    while (aux != NULL){    
        Node *prox = aux->proximo;
        free(aux);
        aux = prox;
        }
    free(lista);
}
