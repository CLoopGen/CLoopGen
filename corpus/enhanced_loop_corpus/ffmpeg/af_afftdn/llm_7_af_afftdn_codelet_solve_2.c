#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < size - 1; i++) {
    for (int j = size - 1; j > i; j--) { // Reverse inner loop direction: changes loop-carried dependency order (still valid)
        double d = matrix[j + i * size];
        vector[j] -= d * vector[i]; // RAW dependency preserved, but iteration space traversed backwards
    }
}
}
