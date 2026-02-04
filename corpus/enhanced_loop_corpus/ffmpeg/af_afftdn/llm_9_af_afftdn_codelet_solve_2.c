#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < size - 1; i += 2) {
    if (i + 1 >= size) break;
    for (int j = i + 1; j < size; j++) {
        double di = matrix[j + i * size];
        double di1 = matrix[j + (i + 1) * size];
        vector[j] -= di * vector[i] + di1 * vector[i + 1];
    }
}
}
