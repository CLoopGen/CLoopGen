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

ZMAT *in;
ZMAT *out;
int i;
int j;

void init_vars() {
    // Set dimensions to achieve ~100-200MB of data for meaningful runtime (~0.01 sec on modern CPU)
    u_int m = 4096;
    u_int n = 4096;

    // Allocate input and output ZMAT structures
    in = (ZMAT*)malloc(sizeof(ZMAT));
    out = (ZMAT*)malloc(sizeof(ZMAT));

    // Initialize dimensions
    in->m = m;
    in->n = n;
    in->max_m = m;
    in->max_n = n;
    in->max_size = m * n;

    out->m = n;
    out->n = m;
    out->max_m = n;
    out->max_n = m;
    out->max_size = m * n;

    // Allocate base arrays
    in->base = (complex*)calloc(m * n, sizeof(complex));
    out->base = (complex*)calloc(m * n, sizeof(complex));

    // Allocate row pointers for me
    in->me = (complex**)malloc(m * sizeof(complex*));
    out->me = (complex**)malloc(n * sizeof(complex*));

    // Assign row pointers: in->me[i] points to row i (each of n elements)
    for (u_int i = 0; i < m; i++) {
        in->me[i] = &in->base[i * n];
    }

    // Assign row pointers for out: out->me[j] points to row j (each of m elements)
    for (u_int j = 0; j < n; j++) {
        out->me[j] = &out->base[j * m];
    }

    // Initialize input data with non-zero values to make transformation observable
    for (u_int i = 0; i < m; i++) {
        for (u_int j = 0; j < n; j++) {
            in->me[i][j].re = (double)(i + j);
            in->me[i][j].im = (double)(i - j);
        }
    }

    // Ensure output is zero-initialized (already done by calloc)
}