#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern int i;
extern MAT *R1;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access pattern
    // Transform the original diagonal access into a consecutive memory layout access
    // by leveraging the fact that R1->base may store data in row-major order.
    // Assume R1->base is a flattened version of the matrix where element (j,j) is at index j*(n+1)
    // Here we assume max_n is the number of columns and same as max_m for square-like access.
    double *flat = R1->base;
    u_int stride = R1->max_n + 1; // diagonal stride in flattened storage
    for (j = 1; j <= i; j++) {
        flat[j * stride] -= 1.0;
    }
}
