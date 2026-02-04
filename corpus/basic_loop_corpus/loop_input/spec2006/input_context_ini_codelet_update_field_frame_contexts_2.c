#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int number_of_slices;

int ***initialized;
int ***model_number;
int i;
int j;

void init_vars() {
    number_of_slices = 1024 * 256; // ~64MB per 3D array (total ~128MB)

    int slices = (number_of_slices + 1) >> 1;
    int levels = 2;
    int dim_j = 4;

    initialized = (int***)calloc(levels, sizeof(int**));
    model_number = (int***)calloc(levels, sizeof(int**));

    for (int l = 0; l < levels; l++) {
        initialized[l] = (int**)calloc(dim_j, sizeof(int*));
        model_number[l] = (int**)calloc(dim_j, sizeof(int*));

        for (int j_idx = 0; j_idx < dim_j; j_idx++) {
            initialized[l][j_idx] = (int*)calloc(slices * 2, sizeof(int));
            model_number[l][j_idx] = (int*)calloc(slices * 2, sizeof(int));

            for (int i_idx = 0; i_idx < slices * 2; i_idx++) {
                initialized[l][j_idx][i_idx] = rand() % 100;
                model_number[l][j_idx][i_idx] = rand() % 100;
            }
        }
    }
}