#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *array;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < size - 1; i++) {
    double temp_diag = array[i + i * size];
    for (int k = i + 1; k < size; k++) {
        double factor = array[i + k * size];
        for (int j = i + 1; j < size; j++) {
            double d = (j == i + 1) ? array[j + i * size] / temp_diag : 0;
            if (j == i + 1) {
                array[j + i * size] = d;
            }
            array[j + k * size] -= d * factor;
        }
    }
}
}
