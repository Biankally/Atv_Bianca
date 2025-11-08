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


Elemento* criar_fila();
int lista_vazia(Fila* fila);
void liberar_fila(Fila* fila);
void enfileirar(Fila* fila, paciente dados);
void print_paciente(paciente c);
paciente adicionar_paciente(int id, const char* nome);