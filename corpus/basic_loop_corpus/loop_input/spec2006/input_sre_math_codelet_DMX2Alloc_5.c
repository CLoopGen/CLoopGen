#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int rows;
int cols;
double **mx;
int r;

void init_vars() {
    rows = 100000;
    cols = 100;
    
    double *data = (double *)calloc(rows * cols, sizeof(double));
    mx = (double **)malloc(rows * sizeof(double *));
    mx[0] = data;
    
    for (int i = 1; i < rows; i++) {
        mx[i] = mx[0] + i * cols;
    }
}