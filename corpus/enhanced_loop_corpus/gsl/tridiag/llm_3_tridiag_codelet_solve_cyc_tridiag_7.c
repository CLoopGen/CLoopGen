#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern double *delta;
extern double *alpha;
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
size_t indices[] = {1, 3, 5, 7, 9, 11}; // Example strided access pattern
size_t num_indices = 6;
for (i = 0; i < num_indices; i++) {
    size_t idx = indices[i];
    if (idx < N - 2) {
        sum += alpha[idx] * delta[idx] * delta[idx];
    }
}
}
