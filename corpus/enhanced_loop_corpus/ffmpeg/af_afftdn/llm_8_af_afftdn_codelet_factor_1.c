#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *array;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < size; i += 2) {
        if (i + 1 >= size) break;
        double diag_inv1 = 1.0 / array[i + i * size];
        double diag_inv2 = 1.0 / array[(i+1) + (i+1) * size];
        for (int j = i + 1; j < size; j++) {
            double d1 = array[j + i * size] * diag_inv1;
            double d2 = array[j + (i+1) * size] * diag_inv2;
            array[j + i * size] = d1;
            array[j + (i+1) * size] = d2;
            for (int k = i + 1; k < size; k++) {
                array[j + k * size] -= d1 * array[i + k * size] + d2 * array[(i+1) + k * size];
            }
        }
    }
}
