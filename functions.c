#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"


double generate_random(double min, double max)
{
    // function which returns a value between min and max
    double value = ((double)rand() / RAND_MAX) * (max - min) + min; 
    return value;
}

int generate_int(int min, int max)
{
    // function which returns a random integer value
    int value = rand() % (max - min) + min; 
    return value;
}

// Function to initialize a random population
void generate_population(int POPULATION_SIZE, int NUM_VARIABLES, double population[POPULATION_SIZE][NUM_VARIABLES], double Lbound[NUM_VARIABLES], double Ubound[NUM_VARIABLES])
{
    // randomly initialize for all values in "population[i][j]""
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        for (int j = 0; j < NUM_VARIABLES; j++)
        {
            population[i][j] = generate_random(Lbound[j],Ubound[j]);
        }
    }
}

// Function to compute the objective function for each member of the population
void compute_objective_function(int POPULATION_SIZE, int NUM_VARIABLES, double population[POPULATION_SIZE][NUM_VARIABLES], double fitness[POPULATION_SIZE])
{
    /* Compute "fitness[i]"" for each set of decision variables (individual) or each row in "population"
    by calling "Objective_function" */
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        fitness[i] = Objective_function(NUM_VARIABLES, population[i]);
    }
}

void crossover(int POPULATION_SIZE, int NUM_VARIABLES, double fitness[POPULATION_SIZE], double new_population[POPULATION_SIZE][NUM_VARIABLES], double population[POPULATION_SIZE][NUM_VARIABLES], double crossover_rate)
{
    /* Implement the logic of crossover function based on "fitness_probs" or each set
    of decision variables (individual) or each row in "population".
    And save the new population in "new_population"*/

    // step 1: we initialized the population in main
    // step 2: we have computed values of objective function in main
    // step 3: compute the fitness probability (fitness_probs) of each member and normalize it
    double fitness_probs[POPULATION_SIZE];

    for (int m = 0; m < POPULATION_SIZE; m++)
    {
        fitness_probs[m] = 1.0 / (1e-15 + fitness[m]);
    }

    double sum = 0;

    for (int m = 0; m < POPULATION_SIZE; m++)
    {
        sum += fitness_probs[m];
    }

    for (int m = 0; m < POPULATION_SIZE; m++)
    {
        fitness_probs[m] = fitness_probs[m] / sum;
    }

   // step 4: compute the cumulative probability values
    double cu_prob[POPULATION_SIZE];

    for (int c = 0; c < POPULATION_SIZE; c++)
    {
        if (c == 0)
        {
            cu_prob[c] = fitness_probs[c];
        }
        else
        {
            cu_prob[c] = cu_prob[c - 1] + fitness_probs[c];
        }
    }

    // step 5: create index array
    int indices[POPULATION_SIZE];

    for (int y = 0; y < POPULATION_SIZE; y++)
    {
       double rand_num = generate_random(0.0, 1.0);

       for (int i = 0; i < POPULATION_SIZE; i++)
       {
            if (rand_num < cu_prob[i])
            {
                indices[y] = i;
                break;
            }
       }
    }

    // step 6: making new population
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        for (int j = 0; j < NUM_VARIABLES; j++)
        {
            new_population[i][j] = population[indices[i]][j];
        }
    }


    // step 7: performing the crossover
    double child1[NUM_VARIABLES];
    double child2[NUM_VARIABLES];

    for (int k = 0; k < POPULATION_SIZE; k = k + 2)
    {
        double R = generate_random(0.0, 1.0);

        if (R < crossover_rate)
        {
            int CP = generate_int(0, NUM_VARIABLES);

            for (int p = 0; p <= CP; p++)
            {
                child1[p] = new_population[k][p];
                child2[p] = new_population[k + 1][p];
            }

            for (int v = CP + 1; v < NUM_VARIABLES; v++)
            {
                child1[v] = new_population[k + 1][v];
                child2[v] = new_population[k][v];
            }

            for (int z = 0; z < NUM_VARIABLES; z++)
            {
                new_population[k][z] = child1[z];
                new_population[k + 1][z] = child2[z];
            }
        }
    }
}

void mutate(int POPULATION_SIZE, int NUM_VARIABLES, double new_population[POPULATION_SIZE][NUM_VARIABLES], double population[POPULATION_SIZE][NUM_VARIABLES], double Lbound[NUM_VARIABLES], double Ubound[NUM_VARIABLES], double mutate_rate)
{
    /*Implement the logic of mutation on "new_population" and then copy everything into "population"*/
    int total_gen = POPULATION_SIZE * NUM_VARIABLES;   // computing total number of variables in population array

    int num_mut = (int) mutate_rate * total_gen;   // computing number of mutations

    for (int n = 0; n < num_mut; n++)   // ensuring only the correct number of mutations occur
    {
        int s = generate_int(0, total_gen - 1);   

        int row = s / NUM_VARIABLES;
        int col = s % NUM_VARIABLES;

        new_population[row][col] = generate_random(Lbound[col], Ubound[col]);   // making the mutation
    }

    for (int l = 0; l < POPULATION_SIZE; l++)   // copying new population array into the population array
    {
        for (int m = 0; m < NUM_VARIABLES; m++)
        {
            population[l][m] = new_population[l][m];
        }
    }
}