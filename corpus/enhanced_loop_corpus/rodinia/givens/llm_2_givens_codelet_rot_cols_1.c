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
    // Variant 1: Consecutive memory access by flattening the 2D matrix access into a 1D pattern
    // Assuming row-major order and that each row has 'max_n' elements
    u_int stride = mat->max_n;
    double *out_i = &(out->me[0][i]); // Base pointer to column i of first row
    double *out_k = &(out->me[0][k]); // Base pointer to column k of first row

    for (j = 0; j < mat->m; j++) {
        double temp_val = c * out_i[j * stride] + s * out_k[j * stride];
        out_k[j * stride] = -s * out_i[j * stride] + c * out_k[j * stride];
        out_i[j * stride] = temp_val;
    }
}
