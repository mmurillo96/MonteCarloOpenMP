# MonteCarloOpenMP
 - O arquivo MonteCarloV2 contem o algoritimo para calcular o valor de PI utilizando a estrategia monte carlo com OpenMP

gcc -o mcV2 -fopenmp MonteCarloV2.c

./mcV2 2 8 1

primeiro passa a quantidade de threads, depois a potencia para a quantidade de pontos e por ultimo um numero aleatorio para tornar a seed exclusiva
