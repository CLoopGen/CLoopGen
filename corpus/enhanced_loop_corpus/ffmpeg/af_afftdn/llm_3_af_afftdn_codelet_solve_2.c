#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access Pattern via Loop Interchange Simulation
    // Reorder computation to improve spatial locality in matrix access by flipping loop order,
    // approximating a more cache-friendly traversal, while maintaining correctness.
    for (int j = 1; j < size; j++) {
        double vj = vector[j];
        for (int i = 0; i < j && i < size - 1; i++) {
            int idx = j + i * size; // Original matrix access remains, but now i is inner
            double d = matrix[idx];
            vj -= d * vector[i];
        }
        vector[j] = vj; // Write back after accumulation
    }
}
