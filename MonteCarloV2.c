#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]) {
    //argumento 1 numero de threads
    //argumento 2 potencia
    
    long i, numIn, n, potencia;
    unsigned int seed;
    double x, y, pi;
    long quantThread = atoi(argv[1]);
    double start_time,end_time;

    omp_set_num_threads(atoi(argv[1]));//numero de threads
    potencia = atoi(argv[2]);//potencia
    n = 10;

    for (i = 0; i < potencia; i++) {
           n = n*10; 
    }
    
    numIn = 0;

    start_time = omp_get_wtime();

    printf("-----------------------------------\n");
    printf("Potencia: %ld\n",potencia);
    printf("Qtd de pontos Sorteados: %ld\n",n);
    printf("Qtd de pontos Sorteados por Thread: %ld\n",n/quantThread);
    printf("Quantidade de Threads: %ld\n",quantThread);
    printf("-----------------------------------\n");

    #pragma omp parallel private(seed, x, y) reduction(+:numIn) 
    {
        seed = 25234 + 17 * omp_get_thread_num();
        //printf("Numero de Thread: %i\n",omp_get_thread_num());
        int thread = omp_get_thread_num();
        long n_thread = n / quantThread;
        //printf("Quant Pontos Thread: %i\n",n_thread);

        #pragma omp for       
            for (i = 0; i <= n_thread ; i++) {
                x = (double)rand_r(&seed) / RAND_MAX;
                y = (double)rand_r(&seed) / RAND_MAX;
                if (x*x + y*y <= 1){
                    numIn++;
                }
            }        
    }
    
    pi = 4.*(numIn*quantThread) / n;
    
    end_time=omp_get_wtime();

    printf("\nResultado PI: %f \n", pi);

    printf("Tempo gasto: %0.8f s\n",(end_time-start_time));    

    return 0;
}
