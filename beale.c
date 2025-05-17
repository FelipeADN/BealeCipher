#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include "lista.h"
#include "gerarChaves.h"
#include "codificarMensagem.h"
#include "decodificarMensagem.h"
#define TAM_LISTA 94 //94 eh o numero de characteres do ascii


int main(int argc, char *argv[]){

    srand(time(NULL));
    // srand(0);

    if (argc == 1){
        printf("Nao passou nenhuma opcao\n");
        exit(1);
    }

    int opcao; //opcao para usar o getopt

    //flags para definir acoes e limitar opcoes incorretas
    int encodeFlag = 0;
    int decodeFlag = 0;
    int livroFlag = 0;
    char *livroString;
    int originalFlag = 0;
    char *originalString;
    int arquivoFlag = 0;
    char *arquivoString;
    int codificadaFlag = 0;
    char *codificadaString;
    int saidaFlag = 0;
    char *saidaString;

    while((opcao = getopt(argc, argv, "edb:m:c:i:o:")) != -1){
        switch (opcao)
        {
        case 'e': //Encode
            encodeFlag = 1;
            break;
        case 'd': //Decode
            decodeFlag = 1;
            break;
        case 'b': //livro cifra
            livroFlag = 1;
            livroString = optarg;
            break;
        case 'm': //mensagem original
            originalFlag = 1;
            originalString = optarg;
            break;
        case 'c': //arquivo de chaves
            arquivoFlag = 1;
            arquivoString = optarg;
            break;
        case 'i'://mensagem codificada
            codificadaFlag = 1;
            codificadaString = optarg;
            break;
        case 'o'://saida
            saidaFlag = 1;
            saidaString = optarg;
            break;
        case ':':
            printf("Nao passou argumento para alguma opcao que precisa de argumento\n");
            break;
        default:
            printf("Opcao desconhecida\n");
            exit(1);
        }
    }

    if (encodeFlag == 1 && decodeFlag == 1){
        printf("nao eh possivel utilizar -e(codificar) e -d(decodificar) ao mesmo tempo\n");
        exit(1);
    }
    if (encodeFlag == 1){
        if (originalFlag == 0){
            printf("para -e(codificar) eh preciso -m(mensagem original)\n");
            exit(1);
        }
        if (livroFlag == 1){
            Lista *listas[TAM_LISTA]; //inicializa TAM_LISTA ponteiros para listas uma por character
            inicializarListas(listas);

            criaChaves(listas, livroString);
            
            if (arquivoFlag == 1){ //salva em arquivo
                guardaChaves(listas, arquivoString, arquivoFlag);
            }
            //codifica e salva
            codificarMensagem(listas, originalString, saidaString, saidaFlag);
            
            desalocarChaves(listas);
        }
        else{
            if (arquivoFlag == 1){
                Lista *listas[TAM_LISTA]; //inicializa TAM_LISTA ponteiros para listas uma por character
                inicializarListas(listas);

                lerChaves(listas, arquivoString); //gera listas com o arquivo
                
                //codifica e salva
                codificarMensagem(listas, originalString, saidaString, saidaFlag);

                desalocarChaves(listas);
            }
            else{
                printf("nao eh possivel -e(codificar) sem pelo menos -b(livro cifra) ou -c(arquivo de chaves)\n");
                exit(1);
            }
        }
    }
    else if (decodeFlag == 1){
        if (codificadaFlag == 1){
            if (livroFlag == 1){
                Lista *listas[TAM_LISTA]; //inicializa TAM_LISTA ponteiros para listas uma por character
                inicializarListas(listas);

                criaChaves(listas, livroString); //gera listas a partir do livro

                decodificarMensagem(listas, codificadaString, saidaString, saidaFlag);

                desalocarChaves(listas);
            }
            else if (arquivoFlag == 1){
                Lista *listas[TAM_LISTA]; //inicializa TAM_LISTA ponteiros para listas uma por character
                inicializarListas(listas);

                lerChaves(listas, arquivoString); //gera listas a partir do arquivo de chaves

                decodificarMensagem(listas, codificadaString, saidaString, saidaFlag);

                desalocarChaves(listas);
            }
            else{
                printf("para -d(decodificar) eh preciso -c(arquivo de chaves) ou -b(livro cifra)\n");
            }
        }
        else{
            printf("para -d(decodificar) eh preciso -i(mensagem codificada)\n");
            exit(1);
        }
    }
    else{
        printf("-e (codificar) ou -d(decodificar) são obrigatórios\n");
        exit(1);
    }
    return 0;
}