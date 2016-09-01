#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

int main(){

    struct processo{
        int tempoExec;
        int tempoEspera;
        int tempoVida;
        int prioridade;
    };


    int numProc,mediaTempoEspera=0,mediaTempoVida=0,i,j, trocasContexto=0;
    printf("Quantidade de processos(max 20):");
    scanf("%d",&numProc);
    struct processo processos[numProc];

    printf("\nTempo de execucao e prioridade do processo\n");
    for(i=0;i<numProc;i++)
    {
        printf("P[%d]:",i+1);
        printf("\nTempo de execucao:");
        scanf("%d",&processos[i].tempoExec);

        printf("\nPrioridade:");
        scanf("%d",&processos[i].prioridade);

    }

    processos[0].tempoEspera=0;    //tempo de espera para o primeiro processo eh 0

    //calculando tempo de espera
    for(i=1;i<numProc;i++)
    {
        processos[i].tempoEspera=0;
        for(j=0;j<i;j++)
            processos[i].tempoEspera+=processos[j].tempoExec;
    }

    printf("\nProcesso\tTempo Execucao\tTempo Espera\tTempo de Vida");

    //calculando tempo de Vida
    for(i=0;i<numProc;i++)
    {

        processos[i].tempoVida= processos[i].tempoExec+ processos[i].tempoEspera;
        mediaTempoEspera+=processos[i].tempoEspera;
        mediaTempoVida+=processos[i].tempoVida;

        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1, processos[i].tempoExec, processos[i].tempoEspera, processos[i].tempoVida);
        //sleep(tempoExec[i]);
        if (i != 0){
            trocasContexto++;
        }
    }
    mediaTempoEspera /= numProc;
    mediaTempoVida /= numProc;

    printf("\n\nMedia de tempo de espera:%d",mediaTempoEspera);
    printf("\nMedia Tempo de vida:%d",mediaTempoVida);
    printf("\nTrocas de contexto:%d",trocasContexto);
    return 0;
}
