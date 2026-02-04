#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = size - 1; i >= 0; i -= 2) {
        if (i == 0) {
            double d = vector[0];
            for (int j = 1; j < size; j++)
                d -= matrix[j * size] * vector[j];
            vector[0] = d / matrix[0];
        } else {
            double d1 = vector[i], d2 = vector[i-1];
            int j_start = (i == size - 1) ? i + 1 : i - 1;
            for (int j = i + 1; j < size; j++) {
                d1 -= matrix[i + j * size] * vector[j];
                d2 -= matrix[(i-1) + j * size] * vector[j];
            }
            vector[i] = d1 / matrix[i + i * size];
            if (i - 1 >= 0)
                vector[i-1] = d2 / matrix[(i-1) + (i-1) * size];
        }
    }
}
