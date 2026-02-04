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
complex temp1;
complex temp2;

void init_vars() {
    // Set up dimensions to achieve desired memory size (~64MB of complex data)
    u_int n = 8000;  // number of columns
    u_int m = 2000;  // number of rows

    // Allocate base matrices
    complex *base_mat = (complex*)calloc(n * m, sizeof(complex));
    complex *base_out = (complex*)calloc(n * m, sizeof(complex));

    // Allocate row pointers for me
    complex **me_mat = (complex**)malloc(m * sizeof(complex*));
    complex **me_out = (complex**)malloc(m * sizeof(complex*));

    for (u_int row = 0; row < m; row++) {
        me_mat[row] = &base_mat[row * n];
        me_out[row] = &base_out[row * n];
    }

    // Initialize mat
    mat = (ZMAT*)malloc(sizeof(ZMAT));
    mat->m = m;
    mat->n = n;
    mat->max_m = m;
    mat->max_n = n;
    mat->max_size = n * m;
    mat->base = base_mat;
    mat->me = me_mat;

    // Initialize out
    out = (ZMAT*)malloc(sizeof(ZMAT));
    out->m = m;
    out->n = n;
    out->max_m = m;
    out->max_n = n;
    out->max_size = n * m;
    out->base = base_out;
    out->me = me_out;

    // Initialize indices and constants
    i = 0;
    k = 1;
    c = 0.7071;  // typical rotation factor (cos(pi/4))
    s.re = 0.7071;
    s.im = 0.7071;

    // Ensure that i and k are within valid row range
    if (i >= m) i = m - 1;
    if (k >= m) k = (m > 1) ? m - 2 : 0;

    // Initialize temp values
    temp1.re = 0.0;
    temp1.im = 0.0;
    temp2.re = 0.0;
    temp2.im = 0.0;
    j = 0;
}