#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double L[2000][2000];
extern double x[2000];
extern double b[2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Mapping
    // Use an auxiliary index array to access x[] indirectly, simulating irregular access patterns
    // Since we cannot modify global declarations, we define a local index map on the stack
    int idx_map[2000];
    for (int k = 0; k < n; k++) {
        idx_map[k] = k; // Identity mapping initially, but allows future permutation
    }
    for (i = 0; i < n; i++) {
        x[i] = b[i];
        for (j = 0; j < i; j++) {
            int mapped_j = idx_map[j]; // Indirect access through mapping
            if (mapped_j < i) { // Ensure validity for dependency
                x[i] -= L[i][mapped_j] * x[mapped_j];
            }
        }
        x[i] = x[i] / L[i][i];
    }
}
