#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int ii, jj;
const int tile_size = 8;
for (ii = 0; ii < n1; ii += tile_size) {
    for (jj = 0; jj < n2; jj += tile_size) {
        for (i = ii; i < n1 && i < ii + tile_size; i++) {
            for (j = jj; j < n2 && j < jj + tile_size; j++) {
                const double Bij_real = ((double *)B)[2 * (ldb * i + j)];
                const double Bij_imag = ((double *)B)[2 * (ldb * i + j) + 1];
                ((double *)B)[2 * (ldb * i + j)]       = alpha_real * Bij_real - alpha_imag * Bij_imag;
                ((double *)B)[2 * (ldb * i + j) + 1]   = alpha_real * Bij_imag + alpha_imag * Bij_real;
            }
        }
    }
}
}
