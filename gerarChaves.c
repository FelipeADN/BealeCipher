#include <stdio.h>
#include <stdlib.h>
#include "gerarChaves.h"
#include "lista.h"
#define TAM_LISTA 94 //94 eh o numero de characteres do ascii

void inicializarListas(Lista **listas){
    int i = 0;
    int y = -2; //primeiro valor default
    while (i < TAM_LISTA){
        listas[i] = criaLista((char) i + 33); //aloca uma lista por character
        insereValor(listas[i], y); //insere o valor padrao por character
        i++;
        y--;
    }
}

void criaChaves(Lista **listas, char *livroString){
    FILE *livro = fopen(livroString, "r"); //abre o livro
    if (livro == NULL){
        printf("arquivo nao encontrado\n");
        exit(1);
    }
    
    listas[(fgetc(livro) - 33)]->inicial->valor = 0;//le a primeira palavra

    //pega as chaves do livro, e organiza nas listas
    char c;
    int palavraCont = 0;
    while ((c = fgetc(livro)) != EOF){
        if (c == 32 || c == 10){ //se for um espaco ou linefeed, encontrou uma palavra
            palavraCont++;
            c = fgetc(livro);
            if (c > 32 && c < 128){ //se for um ascii
                if (listas[c - 33]->inicial->valor < 0){ // se eh a primeira vez que encontrou letra
                    listas[c - 33]->inicial->valor = palavraCont; //substitui o valor padrao do character
                }
                else{
                    insereValor(listas[c - 33], palavraCont); //se nao insere nova chave no fim da lista
                }
            }
        }
    }

    fclose(livro); //fecha o livro
}

void lerChaves(Lista **listas, char *arquivoString){
    FILE *arquivo = fopen(arquivoString, "r"); //abre o arquivo de chaves
    if (arquivo == NULL){
        printf("arquivo nao encontrado\n");
        exit(1);
    }

    char c;
    int i = 0;
    while ((c = fgetc(arquivo)) != EOF){
        if (c == 32){ // se for um espaco, le o numero
            int num;
            fscanf(arquivo, "%d", &num);// le o numero

            if (num >= 0){
                if (listas[i]->inicial->valor < 0){ //se for o primeiro numero, substitui o negativo
                    listas[i]->inicial->valor = num;
                }
                else{
                    insereValor(listas[i], num); //insere no fim da lista
                }
            }
        }
        if (c == '\n'){ //se chegar no fim da linha, le a proxima lista
            i++;
        }
    }
    fclose(arquivo);
}

FILE *passouArquivoChaves(int arquivoFlag, char *arquivoString){
    if (arquivoFlag == 1)
        return fopen(arquivoString, "w");
    return fopen("chaves.txt", "w");
}

void guardaChaves(Lista **listas, char *arquivoString, int arquivoFlag){
    //se foi definido nome para o arquivo de chaves
    FILE *arquivoDeChaves = passouArquivoChaves(arquivoFlag, arquivoString);
    if (arquivoDeChaves == NULL){
        printf("arquivo -c de chaves nao encontrado\n");
        exit(1);
    }
    
    //escreve no arquivo aberto, as chaves das listas
    int i = 0;
    while (i < TAM_LISTA){
        fprintf(arquivoDeChaves, "%c:", listas[i]->chave);
        Node *aux = listas[i]->inicial;
        while (aux != NULL){
            fprintf(arquivoDeChaves, " %d", aux->valor);
            aux = aux->proximo;
        }
        fprintf(arquivoDeChaves, "\n");
        i++;
    }

    fclose(arquivoDeChaves); //fecha o arquivo
}

void desalocarChaves(Lista **listas){
    int i = 0;  
    while (i < TAM_LISTA){
        liberaLista(listas[i]);
        i++; //vai pra proxima lista
    }
}