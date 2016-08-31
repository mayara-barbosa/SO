#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

int main(){
    int numProc,tempoExec[20],tempoEspera[20],tempoVida[20],prioridade[20],mediaTempoEspera=0,mediaTempoVida=0,i,j;
    printf("Quantidade de processos(max 20):");
    scanf("%d",&numProc);

    printf("\nTempo de execucao e prioridade do processo\n");
    for(i=0;i<numProc;i++)
    {
        printf("P[%d]:",i+1);
        printf("\nTempo de execucao:");
        scanf("%d",&tempoExec[i]);

        printf("\nPrioridade:");
        scanf("%d",&prioridade[i]);

    }

    tempoEspera[0]=0;    //tempo de espera para o primeiro processo eh 0

    //calculando tempo de espera
    for(i=1;i<numProc;i++)
    {
        tempoEspera[i]=0;
        for(j=0;j<i;j++)
            tempoEspera[i]+=tempoExec[j];
    }

    printf("\nProcesso\tTempo Execucao\tTempo Espera\tTempo de Vida");

    //calculando tempo de Vida
    for(i=0;i<numProc;i++)
    {

        tempoVida[i]=tempoExec[i]+tempoEspera[i];
        mediaTempoEspera+=tempoEspera[i];
        mediaTempoVida+=tempoVida[i];

        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,tempoExec[i],tempoEspera[i],tempoVida[i]);
        //sleep(tempoExec[i]);
    }

    mediaTempoEspera/=i;
    mediaTempoVida/=i;
    printf("\n\nMedia de tempo de espera:%d",mediaTempoEspera);
    printf("\nMedia Tempo de vida:%d",mediaTempoVida);

    return 0;
}
