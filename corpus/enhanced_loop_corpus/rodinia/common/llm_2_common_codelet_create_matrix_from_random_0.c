#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern float *l;
extern float *u;
extern float *m;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to use row-major stride with consecutive access for better cache locality
    // Here, we precompute base indices for l[i] and u[j] to promote reuse and ensure m[i][j] is updated with unit stride
    for (i = 0; i < size; i++) {
        int base_i = i * size;
        for (j = 0; j < size; j++) {
            int base_j = j * size;
            float sum = 0.0f;
            for (k = 0; k <= ((i < j) ? i : j); k++) {
                sum += l[base_i + k] * u[base_j + k];  // Consecutive access along rows of l and u
            }
            m[base_i + j] = sum;  // Write once with consecutive destination access
        }
    }
}
