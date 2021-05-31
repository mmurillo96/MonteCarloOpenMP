# MonteCarloOpenMP
 - O arquivo MonteCarlo esta desatualizado e não deve ser considerado
 - O arquivo MonteCarloV2 contem o algoritimo para calcular o valor de PI utilizando a estrategia monte carlo com OpenMP

gcc -o mcV2 -fopenmp MonteCarloV2.c

./mcV2 2 8

primeiro passa a quantidade de threads e depois a potencia para a quantidade de pontos
