#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

int i;
MAT *R1;
int j;

void init_vars() {
    i = 5000;  // Set loop bound so that j goes from 1 to 5000

    R1 = (MAT *)malloc(sizeof(MAT));
    R1->max_m = i + 1;
    R1->max_n = i + 1;
    R1->max_size = (i + 1) * (i + 1);
    R1->m = i + 1;
    R1->n = i + 1;

    // Allocate base array large enough for all elements
    R1->base = (double *)calloc((i + 1) * (i + 1), sizeof(double));

    // Allocate array of row pointers
    R1->me = (double **)malloc((i + 1) * sizeof(double *));
    for (int row = 0; row <= i; row++) {
        R1->me[row] = &(R1->base[row * (i + 1)]);
    }

    // Initialize matrix with non-zero values for visible effect
    for (int row = 1; row <= i; row++) {
        for (int col = 1; col <= i; col++) {
            R1->me[row][col] = 2.0;
        }
    }
}