#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    //argumento 2 potencia
    
    if(argc < 2){
        printf("Digite todos os parametros.\n");
        return 0;
    }
    
    long i, contValidos, totalPontos, potencia;
    double x, y, pi;
    clock_t start, end;
    
    potencia = atoi(argv[1]);
    totalPontos = 1;
    contValidos = 0;

    for (i = 0; i < potencia; i++) {
           totalPontos = totalPontos*10; 
    }
    
    printf("-----------------------------------\n");
    printf("Potencia: %ld\n",potencia);
    printf("Qtd de pontos Sorteados: %ld\n",totalPontos);
    
    

    start = clock();

    for (i = 0; i <= totalPontos; i++) {
        x = (double)rand() / (double)RAND_MAX;
        y = (double)rand() / (double)RAND_MAX;
        if (x*x + y*y <= 1) contValidos++;
    }

    pi = 4.*contValidos / totalPontos;
    

    printf("Resultado PI: %f \n", pi);

    end = clock();
    
    printf("Tempo gasto: %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);    

    printf("-----------------------------------\n");

    return 0;
}
