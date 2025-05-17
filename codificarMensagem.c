#include <stdio.h>
#include <stdlib.h>
#include "codificarMensagem.h"
#include "lista.h"

int selecionaIndice(Lista **listas, int c){
    int indice = rand() % (listas[c - 33]->tamanho); //funcao rand para selecionar um indice da lista
        //caminha ate a posicao do indice e pega a chave
        int y = 0;
        Node *aux = listas[c - 33]->inicial;
        while (y < indice){
            aux = aux->proximo;
            y++;
        }
       
       return aux->valor;
}

FILE *passouSaidaCodificar(int saidaFlag, char *saidaString){
    if (saidaFlag == 1)
        return fopen(saidaString, "w");
    return fopen("saidaCodificada.txt", "w");
}

void codificarMensagem(Lista **listas, char *originalString, char *saidaString, int saidaFlag){
    FILE *mensagem = fopen(originalString, "r"); //ler arquivo de mensagem
    if (mensagem == NULL){
        printf("arquivo %s nao encontrado", originalString);
        exit(1);
    }

    //gerar arquivo de saida, dependendo se usuario passou ou nao um nome para a saida
    FILE *saida = passouSaidaCodificar(saidaFlag, saidaString);
    if (saida == NULL){
        printf("arquivo -o saida nao encontrado");
        exit(1);
    }

    char c;
    int i = 0;
    while ((c = fgetc(mensagem)) != EOF){
        if (c == 32 || c == '\n'){ //se for espaco
            fputs("-1 ", saida); //adiciona -1
            i++;
        }
        else if (c > 32 && c < 128){ //se for um ascii
            fprintf(saida, "%d ", selecionaIndice(listas, c)); //adiciona a chave no arquivo de saida
            i++;
        }
        else{
            i++;
        }
    }
    
    //fechar arquivos
    fclose(mensagem);
    fclose(saida);
}