#include <unistd.h>
#include <stdio.h>

/*Ao contrário do round robin, neste algoritmo fatores externos são considerados para a escolha do próximo processo a ganhar o processador.
A idéia básica é muito simples: a cada processo é associada uma prioridade, e o processo pronto com maior prioridade será aquele que vai rodar primeiro.
Para evitar que processos com alta prioridade monopolizem o processador, 
o escalonador decrementa a prioridade do processo que está rodando, a cada interrupção de tempo. Se tal ação fizer com que a prioridade do processo corrente torne-se mais baixa que a do de mais alta prioridade da fila de prontos, deve ocorrer uma troca de contexto.*/

int main()
{
    int numProc,tempoExec[20],tempoEspera[20],tempoTurnaround[20],prioridade[20],mediaTempoEspera=0,mediaTempoTurnaround=0,i,j;
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

    printf("\nProcesso\tTempo Execucao\tTempo Espera\tTurnaround");

    //calculando tempo de turnaround
    for(i=0;i<numProc;i++)
    {

        tempoTurnaround[i]=tempoExec[i]+tempoEspera[i];
        mediaTempoEspera+=tempoEspera[i];
        mediaTempoTurnaround+=tempoTurnaround[i];

        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,tempoExec[i],tempoEspera[i],tempoTurnaround[i]);
        sleep(tempoExec[i]);
    }

    mediaTempoEspera/=i;
    mediaTempoTurnaround/=i;
    printf("\n\nMedia de tempo de espera:%d",mediaTempoEspera);
    printf("\nMedia turnaround:%d",mediaTempoTurnaround);

    return 0;
}
