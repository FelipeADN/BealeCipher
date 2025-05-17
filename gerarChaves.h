#ifndef GERAR_CHAVES_H
#define GERAR_CHAVES_G

#include "lista.h"

//inicializa um vetor de listas dinamicas, uma para cada character ascii
void inicializarListas(Lista **listas);

//adiciona chaves nas listas a partir de um livro
void criaChaves(Lista **listas, char *livroString);

//coloca as chaves nas listas a partir de um arquivo de chaves
void lerChaves(Lista **listas, char *arquivoString);

//guarda chaves em um arquivo, se nao for indicado nome do arquivo, o padrao eh (chaves.txt)
void guardaChaves(Lista **listas, char *arquivoString, int arquivoFlag);

//gera arquivo de chaves, dependendo se usuario passou -c com o nome, se nao o padrao eh (chaves.txt)
FILE *passouArquivoChaves(int arquivoFlag, char *arquivoString);

//desaloca o vetor de listas dinamicas
void desalocarChaves(Lista **listas);

#endif
