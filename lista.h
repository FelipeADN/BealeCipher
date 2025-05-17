#ifndef LISTA_H
#define LISTA_H


//estrutura do node com as posicoes
typedef struct nodeStruct
{
    int valor;
    struct nodeStruct *proximo;
}Node;

//estrutura da lista
typedef struct listaStruct
{
    char chave;
    int tamanho;
    Node *inicial;
}Lista;

//aloca espaco para a lista
Lista *criaLista(char chave);

//insere valor na lista
void insereValor(Lista *lista, int valor);

//desaloca espaco da lista
void liberaLista(Lista *lista);

#endif