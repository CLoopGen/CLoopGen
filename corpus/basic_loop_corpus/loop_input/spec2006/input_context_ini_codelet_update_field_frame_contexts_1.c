#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int number_of_slices = 65536;

int ***initialized;
int ***model_number;
int i;
int j;

void init_vars() {
    // Allocate 3D arrays: [2][4][number_of_slices]
    initialized = (int ***)calloc(2, sizeof(int **));
    model_number = (int ***)calloc(2, sizeof(int **));

    for (int p = 0; p < 2; p++) {
        initialized[p] = (int **)calloc(4, sizeof(int *));
        model_number[p] = (int **)calloc(4, sizeof(int *));
        for (int q = 0; q < 4; q++) {
            initialized[p][q] = (int *)calloc(number_of_slices, sizeof(int));
            model_number[p][q] = (int *)calloc(number_of_slices, sizeof(int));
        }
    }

    // Initialize source data to avoid undefined behavior during loop
    for (int p = 1; p < 2; p++) {
        for (int q = 0; q < 4; q++) {
            for (int r = 0; r < number_of_slices; r++) {
                initialized[p][q][r] = rand();
                model_number[p][q][r] = rand();
            }
        }
    }
}