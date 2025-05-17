#ifndef CODIFICAR_MENSAGEM_H
#define CODIFICAR_MENSAGEM_H

#include "lista.h"

//escolhe um indice da lista baseado na funcao rand e retorna a sua chave
int selecionaIndice(Lista **listas, int c);

//gera variavel de saida, dependendo se usuario passou -o com o nome, se nao o padrao eh (saidaCodificada.txt)
FILE *passouSaidaCodificar(int saidaFlag, char *saidaString);

//funcao que organiza a codificacao de uma mensagem
void codificarMensagem(Lista **listas, char *originalString, char *saidaString, int saidaFlag);

#endif
