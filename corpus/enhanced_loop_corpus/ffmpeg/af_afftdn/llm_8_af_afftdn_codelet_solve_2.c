#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < size; i++) {
    double vi = vector[i];
    for (int j = i + 1; j < size; j += 2) {
        if (j + 1 < size) {
            double d1 = matrix[j + i * size];
            double d2 = matrix[j + 1 + i * size];
            vector[j] -= d1 * vi;
            vector[j + 1] -= d2 * vi;
        } else {
            double d1 = matrix[j + i * size];
            vector[j] -= d1 * vi;
        }
    }
}
}
