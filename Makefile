CFLAGS = -std=c99 -g -Wall #flags para compilacao
objects = beale.o lista.o gerarChaves.o codificarMensagem.o decodificarMensagem.o
LDLIBS = -lm #libs de ligacao
CC = gcc

all: beale

beale: $(objects)
	$(CC) $(objects) -g $(LDLIBS) -o beale

beale.o: beale.c lista.h gerarChaves.h codificarMensagem.h decodificarMensagem.h
	$(CC) -c beale.c -g $(CFLAGS)
	
lista.o: lista.c lista.h
	$(CC) -c lista.c -g $(CFLAGS)

gerarChaves.o: gerarChaves.c lista.h gerarChaves.h
	$(CC) -c gerarChaves.c $(CFLAGS)

codificarMensagem.o: codificarMensagem.c lista.h codificarMensagem.h
	$(CC) -c codificarMensagem.c $(CFLAGS)

decodificarMensagem.o: decodificarMensagem.c lista.h decodificarMensagem.h
	$(CC) -c decodificarMensagem.c $(CFLAGS)

clean:$(objects)
	rm -f $(objects) *~

purge: clean
	-rm -f beale
