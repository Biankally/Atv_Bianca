#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} paciente;

typedef struct elemento_fila {
    paciente dados;
    struct fila* prox;
} Elemento;

typedef struct fila{
    Elemento* inicio;
    Elemento* fim;
    int tamanho;
} Fila;


elemento* criar_fila();
void printpaciente(paciente c);
paciente adicionar_paciente(int id, const char* nome);