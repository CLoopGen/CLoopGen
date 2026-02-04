#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double re;
    double im;
} complex;

int i = 1;
int j = 2;
int lo = 0;
int hi = 1023;
int k;
complex **A_me;
complex tmp;

void init_vars() {
    const int nrows = 4;
    const int ncols = 1024;
    const size_t data_size_bytes = nrows * ncols * sizeof(complex);
    
    A_me = (complex**)calloc(nrows, sizeof(complex*));
    if (!A_me) exit(1);
    
    for (int row = 0; row < nrows; row++) {
        A_me[row] = (complex*)calloc(ncols, sizeof(complex));
        if (!A_me[row]) exit(1);
        
        for (int col = 0; col < ncols; col++) {
            A_me[row][col].re = (double)(row * ncols + col) + 1.0;
            A_me[row][col].im = (double)(row * ncols + col) + 2.0;
        }
    }
    
    i = 1;
    j = 2;
    lo = 0;
    hi = ncols - 1;
}