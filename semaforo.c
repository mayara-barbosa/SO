#include <stdlib.h>

/******************************************************************************
* arquivo: semaforo.c 21/09/16
* autor: Gregory e Mayara Barbosa
* curso: Sistemas de Informacao
*******************************************************************************/

typedef struct filaint_st
{
struct filaint_st *prox ; // ponteiro para o próximo da fila
int valor ; // valor gerado para a fila
} filaint_st ;
struct filaint_st *inicio ; // ponteiro para o início da fila
struct filaint_st *fim ; // ponteiro para o fim da fila

/*
while (1)
{
velho = retira_primeiro_elemento_da_fila()
novo = rand() % 100
põe_elemento_no_fim_da_fila (novo)
imprime operação efetuada e estado da fila
}
*/

int* lista[99];

int main(){

    int memint = malloc (sizeof(lista));
    typedef struct dma filaint_st;
    if (memint == NULL) {
          printf ("Erro em alocacao de memoria\n");
          exit (1);
    }

    for (int i = 0; i < 99; i++){

      
  printf("%d", lista[i]);
    }



    while (1){



    }
    return 0;
}
