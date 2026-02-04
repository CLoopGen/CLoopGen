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

extern MAT *mat;
extern MAT *out;
extern u_int i;
extern u_int k;
extern double c;
extern double s;
extern u_int j;
extern double temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed loop order (access every other row, then handle remainder)
    // This introduces non-unit stride and processes rows in reverse to change access pattern
    u_int stride = 2;
    u_int limit = mat->m;

    // First pass: process even indices in reverse (strided access)
    for (j = (limit - 1) & (~(stride - 1)); (int)j >= 0; j -= stride) {
        temp = c * ((out)->me[j][i]) + s * ((out)->me[j][k]);
        ((out)->me[j][k] = (-s * ((out)->me[j][i]) + c * ((out)->me[j][k])));
        ((out)->me[j][i] = temp);
    }

    // Second pass: handle remaining indices (odd indices if any)
    for (j = (limit - 1) | 0; j < limit && j % 2 == 1; j--) {
        temp = c * ((out)->me[j][i]) + s * ((out)->me[j][k]);
        ((out)->me[j][k] = (-s * ((out)->me[j][i]) + c * ((out)->me[j][k])));
        ((out)->me[j][i] = temp);
    }
}
