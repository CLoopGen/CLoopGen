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
    double temp = vector[i]; // Introduce local copy to modify data dependency (reduce WAW/RAR conflicts)
    for (int j = i + 1; j < size; j++) {
        double d = matrix[j + i * size];
        vector[j] = vector[j] - d * temp; // Use cached value: removes potential RAR on vector[i] across iterations
    }
}
}
