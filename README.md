# gam693a
**Final Project for MATH-693A : Fall-2015**

- Angel Boada, <angelboada2@gmail.com>

- Sumukh Sagar Manjunath, <sagar.sumukh@gmail.com>
  ________________________________________________



Genetic Algorithm implemented for the test functions of 2-Dimensions. This is intended to be only for study purpose and not meant to be used in any Industrial scale. Genetic algorithm falls under the category of the Metahueristics branch of optimization which tries optimize the given function in a way a specie in the animal kingdom goes thorugh a series of evolution to find its most fit form.

Each evolutionary cycle starts from assigning each individuals of the population with a fitness value. Individuals are selected randomly to participate in the evolutionary cycle. Some of the members undergo crossover (as we call it mating in the nature) and few individuals mutate to change their nature. Once this is done, existing members of the population are replaced with the new ones at random. This continues until all members of the population are nearly equally fit.

This project has been implemented using C++ as the programing language. You will be needing a g++ compiler to build this program.

### HOW TO USE
**************

1. Download the code base and unzip it.
2. Run "make" inside the terminal.
3. Library will be created in $(BASE)/lib called libgam.a
4. To run the project on the test functions, run the binary files inside $(BASE)/tests/.
