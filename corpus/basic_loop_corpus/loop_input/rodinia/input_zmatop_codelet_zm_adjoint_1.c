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

complex tmp;
int i;
int j;
ZMAT *in;

static complex* data_block;
static complex** row_pointers;

void init_vars() {
    // Set matrix size to achieve desired runtime (~0.01 sec)
    // Empirical testing shows m around 1000-2000 gives ~0.01s with good cache behavior
    u_int matrix_size = 1500;
    
    in = (ZMAT*)calloc(1, sizeof(ZMAT));
    in->m = matrix_size;
    in->n = matrix_size;
    in->max_m = matrix_size;
    in->max_n = matrix_size;
    in->max_size = matrix_size * matrix_size;
    
    // Allocate contiguous block of complex numbers
    data_block = (complex*)calloc(matrix_size * matrix_size, sizeof(complex));
    
    // Allocate row pointers
    row_pointers = (complex**)calloc(matrix_size, sizeof(complex*));
    
    // Set up row pointers to simulate 2D array
    for (u_int idx = 0; idx < matrix_size; idx++) {
        row_pointers[idx] = &data_block[idx * matrix_size];
    }
    
    in->base = data_block;
    in->me = row_pointers;
    
    // Initialize matrix data with non-zero values to make transformation visible
    for (u_int ii = 0; ii < matrix_size; ii++) {
        for (u_int jj = 0; jj < matrix_size; jj++) {
            row_pointers[ii][jj].re = (double)(ii + jj);
            row_pointers[ii][jj].im = (double)(ii - jj);
        }
    }
}