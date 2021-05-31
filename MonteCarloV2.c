#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]) {
    //argumento 1 numero de threads
    //argumento 2 potencia
    
    long i, contSucesso, totalPontos, potencia;
    unsigned int seed;
    double x, y, pi, start_time, end_time;
    long quantThread = atoi(argv[1]);

    omp_set_num_threads(atoi(argv[1]));//numero de threads
    potencia = atoi(argv[2]);//potencia
    totalPontos = 10;

    for (i = 0; i < potencia; i++) {
           totalPontos = totalPontos*10; 
    }
    
    contSucesso = 0;

    start_time = omp_get_wtime();

    printf("-----------------------------------\n");
    printf("Potencia: %ld\n",potencia);
    printf("Qtd de pontos Sorteados: %ld\n",totalPontos);
    printf("Qtd de pontos Sorteados por Thread: %ld\n",totalPontos/quantThread);
    printf("Quantidade de Threads: %ld\n",quantThread);
    printf("-----------------------------------\n");

    #pragma omp parallel private(seed, x, y) reduction(+:contSucesso) 
    {
        //este calculo deve gerar seeds diferentes para cada execução.
        seed = 25234 + potencia * omp_get_thread_num();

        //printf("Numero de Thread: %i\n",omp_get_thread_num());
        int thread = omp_get_thread_num();
        long pontos_thread = totalPontos / quantThread;
        //printf("Quant Pontos Thread: %i\n",n_thread);

        #pragma omp for       
            for (i = 0; i <= pontos_thread ; i++) {
                x = (double)rand_r(&seed) / RAND_MAX;
                y = (double)rand_r(&seed) / RAND_MAX;
                if (x*x + y*y <= 1){
                    contSucesso++;
                }
            }        
    }
    
    pi = 4.*(contSucesso*quantThread) / totalPontos;
    
    end_time=omp_get_wtime();

    printf("\nResultado PI: %f \n", pi);

    printf("Tempo gasto: %0.8f s\n",(end_time-start_time));    

    return 0;
}
