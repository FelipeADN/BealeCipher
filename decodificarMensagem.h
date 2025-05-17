#ifndef DECODIFICAR_MENSAGEM_H
#define DECODIFICAR_MENSAGEM_H

#include "lista.h"

//gera variavel de saida, dependendo se usuario passou -o com o nome, se nao o padrao eh (saidaDecodificada.txt)
FILE *passouSaidaDecodificar(int saidaFlag, char *saidaString);

//percorre por todas as listas buscando a chave, e retorna o character equivalente
char encontrarCharacter(Lista **listas, int chave);

//funcao que organiza a decodificacao de uma mensagem
void decodificarMensagem(Lista **listas, char *codificadaString, char *saidaString, int saidaFlag);

#endif
