#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

su3_matrix *lbuf;
int i;
int j;
int k;

void init_vars() {
    const int size = 4096;
    lbuf = (su3_matrix*)aligned_alloc(32, size * sizeof(su3_matrix));
    if (!lbuf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    memset(lbuf, 0, size * sizeof(su3_matrix));
}