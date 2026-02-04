#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *array;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < size - 1; i++) {
        double denom = array[i + i * size];
        if (denom == 0.0) continue;
        for (int j = i + 1; j < size; j++) {
            double d = array[j + i * size] / denom;
            array[j + i * size] = d;
            for (int k = i + 1; k < size; k += 2) {
                array[j + k * size] -= d * array[i + k * size];
                if (k + 1 < size) {
                    array[j + (k + 1) * size] -= d * array[i + (k + 1) * size];
                }
            }
        }
    }
}
