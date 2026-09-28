# Genetic Algorithm Optimizer

A C implementation of a genetic algorithm for minimizing multivariable objective functions.

The program supports ten standard optimization benchmark functions and allows key genetic algorithm parameters to be configured through command-line arguments.

## Features

* Genetic algorithm for multivariable function optimization
* Ten standard optimization benchmark functions
* Configurable population size
* Configurable maximum number of generations
* Configurable crossover and mutation rates
* Configurable stopping criterion
* Makefile-based compilation and cleanup

## Optimization Functions

* Griewank
* Levy
* Rastrigin
* Schwefel
* Trid
* Dixon-Price
* Rosenbrock
* Michalewicz (`m = 10`)
* Powell
* Styblinski-Tang

## Technologies

* **Language:** C
* **Build System:** Make
* **Libraries & APIs:** `stdio`, `stdlib`, `time`, `float`, `math`

## How to Run

### Requirements

* GCC
* Make
* A Unix-based terminal environment such as macOS or Linux

### 1. Select the objective function

The objective functions are defined in `OF.c`. Modify the relevant code in `GA.c` and `OF.c` to select the function you want to optimize.

### 2. Compile the program

```bash
make
```

### 3. Run the algorithm

```bash
./GA <POPULATION_SIZE> <MAX_GENERATIONS> <crossover_rate> <mutate_rate> <stop_criteria>
```

| Argument          | Description                              |
| ----------------- | ---------------------------------------- |
| `POPULATION_SIZE` | Number of individuals in the population  |
| `MAX_GENERATIONS` | Maximum number of generations            |
| `crossover_rate`  | Probability of crossover                 |
| `mutate_rate`     | Probability of mutation                  |
| `stop_criteria`   | Criterion used to determine when to stop |

### 4. Clean the build

```bash
make clean
```

## Technical Concepts

* Genetic algorithms
* Population-based optimization
* Selection
* Crossover
* Mutation
* Objective functions
* Stopping criteria
* Multivariable optimization
* Modular C programming
* Makefiles and build automation
