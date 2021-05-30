#include <omp.h>
#include <stdio.h>
#include <time.h>

#define RNG_MOD 0x80000000
int state;

int rng_int(void);
double rng_doub(double range);
time_t t;

int main() {
    int i, numIn, n;
    double x, y, pi;

    time_t timeInicio = time(NULL);
    printf("Inicio: %s", ctime(&timeInicio));

    n = 1<<30;
    numIn = 0;
 
   // #pragma omp threadprivate(state)
    #pragma omp parallel private(x, y) reduction(+:numIn) 
    {        
        //state = 25234 + 17 * omp_get_thread_num();    
        #pragma omp for
        for (i = 0; i <= n; i++) {
            x = (double)rng_doub(1.0);
            y = (double)rng_doub(1.0);
            if (x*x + y*y <= 1) numIn++;
        }
    }
    pi = 4.*numIn / n;


    printf("Resultado: pi %f\n", pi);

    //mostra o tempo final
    time_t timeFim = time(NULL);
    printf("Fim: %s", ctime(&timeFim));

    printf("Tempo gasto: %f milissegundos\n", difftime(timeFim, timeInicio));    

    return 0;
}

int rng_int(void) {
   // & 0x7fffffff is equivalent to modulo with RNG_MOD = 2^31
   return (state = (state * 1103515245 + 12345) & 0x7fffffff);
}

double rng_doub(double range) {
    return ((double)rng_int()) / (((double)RNG_MOD)/range);
}
