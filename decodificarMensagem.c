#include <stdio.h>
#include <stdlib.h>
#include "decodificarMensagem.h"
#include "lista.h"
#define TAM_LISTA 94 //94 eh o numero de characteres do ascii

FILE *passouSaidaDecodificar(int saidaFlag, char *saidaString){
    if (saidaFlag == 1)
        return fopen(saidaString, "w");
    return fopen("saidaDecodificada.txt", "w");
}

char encontrarCharacter(Lista **listas, int chave){
    char character;
    int achou = 0;
        int i = 0;
        while (i < TAM_LISTA && achou == 0){ //percorre todas as listas ate achar
            if (listas[i]->inicial->valor < 0) //lista sem chaves, vai pra proxima
                i++;
            else {
                Node *aux = listas[i]->inicial;
                while (aux != NULL) {
                    if (aux->valor == chave){
                        character = listas[i]->chave;
                        achou = 1;
                    }
                    aux = aux->proximo;
                }
                i++;
            }
        }
        if (achou == 0){
            printf("Valor nao encontrado\n");
        }
        return character;
}

void decodificarMensagem(Lista **listas, char *codificadaString, char *saidaString, int saidaFlag){
    FILE *codificada = fopen(codificadaString, "r"); //ler arquivo de mensagem
    if (codificada == NULL){
        printf("arquivo %s nao encontrado\n", codificadaString);
        exit(1);
    }

    //gerar arquivo de saida, dependendo se usuario passou ou nao um nome para a saida
    FILE *saida = passouSaidaDecodificar(saidaFlag, saidaString);
    if (saida == NULL){
        printf("arquivo -o saida nao encontrado\n");
        exit(1);
    }

    int chave;
    while (fscanf(codificada, "%d", &chave) != EOF){
        if (chave < 0){ //se o numero eh negativo, usa a tabela padrao
            int valor = (chave * (-1))+31;
            fprintf(saida, "%c", valor);
        }
        else{ //se nao percorre as listas
            fprintf(saida, "%c", encontrarCharacter(listas, chave));
        }
    }

    fclose(saida);
    fclose(codificada);
}