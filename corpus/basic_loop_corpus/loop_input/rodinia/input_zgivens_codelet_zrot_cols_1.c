#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    complex *base;
    complex **me;
} ZMAT;

ZMAT *mat;
ZMAT *out;
int i;
int k;
double c;
complex s;
u_int j;
complex x;
complex y;

void init_vars() {
    // Set scalar values
    i = 1;
    k = 2;
    c = 0.866; // example cosine value
    s.re = 0.5;
    s.im = 0.866; // example sine value (complex phase)

    // Allocate base matrix dimensions
    mat = (ZMAT*)malloc(sizeof(ZMAT));
    mat->m = 100000;  // ~100K rows to target ~1-2 seconds, will adjust via loop count
    mat->n = 4;
    mat->max_m = mat->m;
    mat->max_n = mat->n;
    mat->max_size = mat->max_m * mat->max_n;

    // Adjust m so that total data is around 1-2MB and loop runs ~0.01s
    // Each complex is 16 bytes, each me[j] has n=4 elements -> 64 bytes per row
    // To get ~1.6MB total: 1.6e6 / 64 ~ 25000 rows
    mat->m = 25000;

    out = (ZMAT*)malloc(sizeof(ZMAT));
    out->m = mat->m;
    out->n = 4;
    out->max_m = out->m;
    out->max_n = out->n;
    out->max_size = out->max_m * out->max_n;

    // Allocate base array
    out->base = (complex*)calloc(out->max_size, sizeof(complex));

    // Allocate row pointers
    out->me = (complex**)malloc(out->m * sizeof(complex*));
    for (u_int idx = 0; idx < out->m; idx++) {
        out->me[idx] = &(out->base[idx * out->n]);
    }

    // Ensure i and k are within bounds [0, n)
    if (i >= (int)out->n) i = out->n - 1;
    if (k >= (int)out->n) k = out->n - 2;

    // Initialize some sample values in the matrix to avoid NaN/inf issues
    for (u_int ii = 0; ii < out->m; ii++) {
        for (u_int jj = 0; jj < out->n; jj++) {
            out->me[ii][jj].re = (double)(ii + jj);
            out->me[ii][jj].im = (double)(ii - jj);
        }
    }
}