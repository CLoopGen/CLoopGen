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

extern MAT *in;
extern MAT *out;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of iterating row-major for input and column-major for output,
    // we access the input matrix with a fixed stride pattern by unrolling and accessing every nth element.
    // Here, we reverse the loop order to column-major traversal to improve spatial locality in output.
    u_int m = in->m;
    u_int n = in->n;
    for (j = 0; j < n; j++)
        for (i = 0; i < m; i++)
            out->me[j][i] = in->me[i][j];
}
