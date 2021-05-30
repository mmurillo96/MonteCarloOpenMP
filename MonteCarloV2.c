#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, numIn, n, potencia;
    unsigned int seed;
    double x, y, pi;

    potencia = 3;
    n = 10;
    for (i = 0; i < potencia; i++) {
           n = n*10; 
    }
    numIn = 0;

    time_t timeInicio = time(NULL);
    printf("Inicio: %s\n", ctime(&timeInicio));


    #pragma omp parallel private(seed, x, y) reduction(+:numIn) 
    {
        seed = 25234 + 17 * omp_get_thread_num();
        //seed = omp_get_thread_num();
        #pragma omp for
        for (i = 0; i <= n; i++) {
            x = (double)rand_r(&seed) / RAND_MAX;
            y = (double)rand_r(&seed) / RAND_MAX;
            if (x*x + y*y <= 1){
                 numIn++;
            }
        }
    }

    pi = 4.*numIn / n;
    
    printf("Resultado: pi %f \n", pi);

    time_t timeFim = time(NULL);
    printf("Fim: %s \n", ctime(&timeFim));

    printf("Tempo gasto: %f milissegundos\n", difftime(timeFim, timeInicio));    

    return 0;
}
