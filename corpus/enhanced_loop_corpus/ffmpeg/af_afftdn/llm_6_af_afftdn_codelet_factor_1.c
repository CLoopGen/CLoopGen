#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *array;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < size - 1; i++) {
    double diag_inv = 1.0 / array[i + i * size];
    for (int j = i + 1; j < size; j++) {
        double d = array[j + i * size] * diag_inv;
        array[j + i * size] = d;
        for (int k = i + 1; k < size; k++) {
            array[j + k * size] = array[j + k * size] - d * array[i + k * size];
        }
    }
}
}
