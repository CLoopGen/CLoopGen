#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double beta;
extern double A[2000][2000];
extern double x[2000];
extern double y[2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification - Introduce indirect array indexing via index mapping
    // Create an auxiliary index array to access y and A indirectly, simulating gather-style access
    int idx[2000];
    for (int k = 0; k < n; k++) {
        idx[k] = (k * 17) % n;  // Generate a pseudo-random permutation using linear congruential pattern
    }
    for (i = 0; i < n; i++) {
        double sum = x[i];
        for (j = 0; j < n; j++) {
            int index = idx[j];  // Indirect access through permuted indices
            sum += beta * A[index][i] * y[index];
        }
        x[i] = sum;
    }
}
