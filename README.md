# Genetic Algorithm Optimizer

This program implements a genetic algorithm to minimize multivariable functions.  
The ten functions supported by this program are:

- Griewank  
- Levy  
- Rastrigin  
- Schwefel  
- Trid  
- Dixon-Price  
- Rosenbrock  
- Michalewicz (with m = 10)  
- Powell  
- Styblinski–Tang

Genetic algorithms are a well-known optimization technique used to find values at which a function is minimized. 
They are based on the biological processes of evolution and natural selection.

## How to run

1. Download all of the files into a single directory.
2. Open the `GA.c` and `OF.c` files in VS Code (or any text editor or IDE).
   - You will need to comment/uncomment code in these files depending on which function you want to optimize.
   - Once your changes are made, continue with the steps below.
3. To compile, run the command:
   ```bash
   make
   ```
4. To run the algorithm, run (replacing the angle brackets with your chosen values):
  ```bash
  ./GA <POPULATION_SIZE> <MAX_GENERATIONS> <crossover_rate> <mutate_rate> <stop_criteria>
  ```
5. To remove the executable from the directory, run:
   ```bash
   make clean
   ```
