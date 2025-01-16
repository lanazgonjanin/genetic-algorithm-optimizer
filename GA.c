#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include <float.h>

int main(int argc, char *argv[])
{
    if (argc != 6)
    {
        printf("Incorrect number of inputs. Please enter the 5 inputs in the following order: population size, maximum number of generations, crossover rate, mutation rate, stop criteria.\n");
        return 1;
    }

    int POPULATION_SIZE = atoi(argv[1]);
    int MAX_GENERATIONS = atoi(argv[2]);
    double crossover_rate = atof(argv[3]);
    double mutate_rate = atof(argv[4]);
    double stop_criteria = atof(argv[5]);

    // LEVY FUNCTION, 10 variables
    int NUM_VARIABLES = 10;
    double Lbound[] = {-5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0};
    double Ubound[] = {5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0};

    // LEVY FUNCTION, 50 variables
    // int NUM_VARIABLES = 50;
    // double Lbound[] = {-5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0};
    // double Ubound[] = {5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0};
    
    // GRIEWANK FUNCTION, 10 variables
    // int NUM_VARIABLES = 10;
    // double Lbound[] = {-600.0, -600.0, -600.0, -600.0, -600.0, -600.0, -600.0, -600.0, -600.0, -600.0};
    // double Ubound[] = {600.0, 600.0, 600.0, 600.0, 600.0, 600.0, 600.0, 600.0, 600.0, 600.0};

    // RASTRIGIN FUNCTION, 10 variables
    // int NUM_VARIABLES = 10;
    // double Lbound[] = {-5.12, -5.12, -5.12, -5.12, -5.12, -5.12, -5.12, -5.12, -5.12, -5.12};
    // double Ubound[] = {5.12, 5.12, 5.12, 5.12, 5.12, 5.12, 5.12, 5.12, 5.12, 5.12};

    // SCHWEFEL FUNCTION, 10 variables
    // int NUM_VARIABLES = 10;
    // double Lbound[] = {-500.0, -500.0, -500.0, -500.0, -500.0, -500.0, -500.0, -500.0, -500.0, -500.0};
    // double Ubound[] = {500.0, 500.0, 500.0, 500.0, 500.0, 500.0, 500.0, 500.0, 500.0, 500.0};

    // TRID FUNCTION, 10 variables
    // int NUM_VARIABLES = 10;
    // double neg_d2 = (double)(-NUM_VARIABLES * NUM_VARIABLES);
    // double d2 = (double)(NUM_VARIABLES * NUM_VARIABLES);
    // double Lbound[] = {neg_d2, neg_d2, neg_d2, neg_d2, neg_d2, neg_d2, neg_d2, neg_d2, neg_d2, neg_d2};
    // double Ubound[] = {d2, d2, d2, d2, d2, d2, d2, d2, d2, d2};

    // DIXON-PRICE FUNCTION, 10 variables
    // int NUM_VARIABLES = 10;
    // double Lbound[] = {-10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0, -10.0};
    // double Ubound[] = {10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0};

    // ROSENBROCK FUNCTION, 10 variables
    //int NUM_VARIABLES = 10;
    //double Lbound[] = {-2.048, -2.048, -2.048, -2.048, -2.048, -2.048, -2.048, -2.048, -2.048, -2.048};
    //double Ubound[] = {2.048, 2.048, 2.048, 2.048, 2.048, 2.048, 2.048, 2.048, 2.048, 2.048};

    // MICHALEWICZ FUNCTION with m = 10, 10 variables
    // int NUM_VARIABLES = 10;
    // double Lbound[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    // double Ubound[] = {3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14};

    // POWELL FUNCTION, 10 variables
    // int NUM_VARIABLES = 10;
    // double Lbound[] = {-4.0, -4.0, -4.0, -4.0, -4.0, -4.0, -4.0, -4.0, -4.0, -4.0};
    // double Ubound[] = {5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0};

    // STYBLINSKI-TANG FUNCTION, 10 variables
    // int NUM_VARIABLES = 10;
    // double Lbound[] = {-5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0};
    // double Ubound[] = {5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0};


    printf("Genetic Algorithm is initiated.\n");
    printf("--------------------------------------------------------------------\n");
    printf("The number of variables: %d\n",NUM_VARIABLES);

    printf("Lower bounds: [");
    for (int l = 0; l < (NUM_VARIABLES - 1); l++)
    {
        printf("%0.3f, ",Lbound[l]);
    }
    printf("%0.3f]\n",Lbound[NUM_VARIABLES - 1]);

    printf("Upper bounds: [");
    for (int u = 0; u < (NUM_VARIABLES - 1); u++)
    {
        printf("%0.3f, ",Ubound[u]);
    }
    printf("%0.3f]\n",Ubound[NUM_VARIABLES - 1]);

    printf("Population size: %d\n",POPULATION_SIZE);
    printf("Maximum number of generations: %d\n",MAX_GENERATIONS);
    printf("Crossover rate: %f\n",crossover_rate);
    printf("Mutation rate: %f\n",mutate_rate);
    printf("Stopping criteria: %0.20f\n",stop_criteria);
    printf("\n");


    clock_t start_time, end_time;
    double cpu_time_used;
    start_time = clock();

    double population[POPULATION_SIZE][NUM_VARIABLES];
    double fitness[POPULATION_SIZE];
    double new_population[POPULATION_SIZE][NUM_VARIABLES];

    double best_fitness = DBL_MAX;
    double best_solution[NUM_VARIABLES];

    srand(time(NULL));

    generate_population(POPULATION_SIZE, NUM_VARIABLES, population, Lbound, Ubound);

    for (int generation = 0; generation < MAX_GENERATIONS; generation++)
    {
        compute_objective_function(POPULATION_SIZE, NUM_VARIABLES, population, fitness);

        for (int c = 0; c < POPULATION_SIZE; c++)
        {
            if (fitness[c] <= best_fitness)
            {
                best_fitness = fitness[c];

                for (int d = 0; d < NUM_VARIABLES; d++)
                {
                    best_solution[d] = population[c][d];
                }
                
            }
        }

        if (best_fitness < stop_criteria)
        {
            break;
        }

        crossover(POPULATION_SIZE, NUM_VARIABLES, fitness, new_population, population, crossover_rate);

        mutate(POPULATION_SIZE, NUM_VARIABLES, new_population, population, Lbound, Ubound, mutate_rate);
    }

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Results\n");
    printf("--------------------------------------------------------------------\n");
    printf("CPU time: %f seconds\n", cpu_time_used);

    printf("Best solution: (");
    for (int e = 0; e < (NUM_VARIABLES - 1); e++)
    {
        printf("%f, ",best_solution[e]);
    }
    printf("%f)\n",best_solution[NUM_VARIABLES - 1]);

    printf("Best fitness: %0.20f\n",best_fitness);

    return 0;
}
