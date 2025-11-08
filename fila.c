#include <fila.h>
#include <stdio.h>
#include <stdlib.h>


paciente adicionar_paciente(int id, const char* nome) {
    paciente paciente;
    paciente.id = id;
    snprintf(paciente.nome, sizeof(paciente.nome), "%s", nome);
    return paciente;

}

Elemento* criar_fila() {

    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila == NULL){
        printf("Erro ao alocar memoria para a fila.\n");
        exit(1);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0; 

    return fila;
}

int lista_vazia(Fila* fila) {
    return fila->tamanho == 0;
}

//FUNÇÃO PARA LIBERAR A FILA
void liberar_fila(Fila* fila) {
    Elemento* atual = fila->inicio;
    while (atual != NULL) {
        Elemento* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(fila);
}

//FUNÇÃO PARA ENFILEIRAR UM PACIENTE
void enfileirar(Fila* fila, paciente dados) {
    Elemento* novo_elemento = (Elemento*) malloc(sizeof(Elemento));
    if(novo_elemento == NULL){
        printf("Erro ao alocar memoria para o novo elemento.\n");
        exit(1);
    }
    novo_elemento->dados = dados;
    novo_elemento->prox = NULL;

    if (fila->fim != NULL) {
        fila->fim->prox = novo_elemento;
    }
    fila->fim = novo_elemento;

    if (fila->inicio == NULL) {
        fila->inicio = novo_elemento;
    }

    fila->tamanho++;
}

//FUNÇÃO PARA DESENFILEIRAR UM PACIENTE
paciente desenfileirar(Fila* fila) {
    if (lista_vazia(fila)) {
        printf("Fila vazia. Nao e possivel desenfileirar.\n");
        exit(1);
    }

    Elemento* temp = fila->inicio;
    paciente dados = temp->dados;
    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);
    fila->tamanho--;

    return dados;
}

//FUNÇÃO PARA OBTER O TAMANHO DA FILA
int tamanho_fila(Fila* fila) {
    return fila->tamanho;
}

//FUNÇÃO PARA IMPRIMIR OS DADOS DE UM PACIENTE
void printpaciente(paciente paciente) {
    printf("ID: %d, Nome: %s\n", paciente.id, paciente.nome);
}

//FUNÇÃO PARA IMPRIMIR A FILA
void imprimir_fila(Fila* fila) {
    Elemento* atual = fila->inicio;
    while (atual != NULL) {
        printpaciente(atual->dados);
        atual = atual->prox;
    }
}


