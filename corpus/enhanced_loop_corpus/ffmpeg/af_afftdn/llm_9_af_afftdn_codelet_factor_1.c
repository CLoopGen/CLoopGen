#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *array;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < size - 1; i++) {
        double pivot = array[i + i * size];
        if (pivot == 0.0) continue;
        for (int j = i + 1; j < size; j++) {
            double d = array[j + i * size] / pivot;
            array[j + i * size] = d;
            int k = i + 1;
            // Unroll inner loop by factor of 4
            int remainder = (size - k) % 4;
            for (int r = 0; r < remainder; r++) {
                array[j + (k + r) * size] -= d * array[i + (k + r) * size];
            }
            for (; k + 3 < size; k += 4) {
                array[j + (k)   * size] -= d * array[i + (k)   * size];
                array[j + (k+1) * size] -= d * array[i + (k+1) * size];
                array[j + (k+2) * size] -= d * array[i + (k+2) * size];
                array[j + (k+3) * size] -= d * array[i + (k+3) * size];
            }
        }
    }
}
