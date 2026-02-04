#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *se;
double *neighbors;
int x;
int y;
int neighY;
int center;
int diameter;

void init_vars() {
    diameter = 1024;
    center = diameter / 2;
    int se_size = diameter * diameter;
    se = (int*)calloc(se_size, sizeof(int));
    int max_neighbors = se_size;
    neighbors = (double*)malloc(max_neighbors * 2 * sizeof(double));
    neighY = 0;

    for (int i = 0; i < se_size; i++) {
        se[i] = rand() % 2;
    }
}