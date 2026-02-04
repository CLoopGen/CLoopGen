#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (size <= 1) return;
double *vec = vector;
double *mat = matrix;
for (int k = 0; k < size - 1; k++) {
    double vk = vec[k];
    int base = k * size;
    for (int i = 0; i < size - 1 - k; i++) {
        int j = i + k + 1;
        vec[j] -= mat[j + base] * vk;
    }
}
}
