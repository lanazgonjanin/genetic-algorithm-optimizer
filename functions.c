#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"


double generate_random(double min, double max)
{
    double value = ((double)rand() / RAND_MAX) * (max - min) + min; 
    return value;
}

int generate_int(int min, int max)
{
    int value = rand() % (max - min) + min; 
    return value;
}

void generate_population(int POPULATION_SIZE, int NUM_VARIABLES, double population[POPULATION_SIZE][NUM_VARIABLES], double Lbound[NUM_VARIABLES], double Ubound[NUM_VARIABLES])
{
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        for (int j = 0; j < NUM_VARIABLES; j++)
        {
            population[i][j] = generate_random(Lbound[j],Ubound[j]);
        }
    }
}

void compute_objective_function(int POPULATION_SIZE, int NUM_VARIABLES, double population[POPULATION_SIZE][NUM_VARIABLES], double fitness[POPULATION_SIZE])
{
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        fitness[i] = Objective_function(NUM_VARIABLES, population[i]);
    }
}

void crossover(int POPULATION_SIZE, int NUM_VARIABLES, double fitness[POPULATION_SIZE], double new_population[POPULATION_SIZE][NUM_VARIABLES], double population[POPULATION_SIZE][NUM_VARIABLES], double crossover_rate)
{
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

    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        for (int j = 0; j < NUM_VARIABLES; j++)
        {
            new_population[i][j] = population[indices[i]][j];
        }
    }

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
    int total_gen = POPULATION_SIZE * NUM_VARIABLES; 

    int num_mut = (int) mutate_rate * total_gen;

    for (int n = 0; n < num_mut; n++)
    {
        int s = generate_int(0, total_gen - 1);   

        int row = s / NUM_VARIABLES;
        int col = s % NUM_VARIABLES;

        new_population[row][col] = generate_random(Lbound[col], Ubound[col]); 
    }

    for (int l = 0; l < POPULATION_SIZE; l++)
    {
        for (int m = 0; m < NUM_VARIABLES; m++)
        {
            population[l][m] = new_population[l][m];
        }
    }
}
