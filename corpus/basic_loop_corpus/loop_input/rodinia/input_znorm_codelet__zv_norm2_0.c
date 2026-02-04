#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int dim;
    u_int max_dim;
    complex *ve;
} ZVEC;

ZVEC *x;
int i;
int dim;
double sum;

void init_vars() {
    dim = 20000000; // Approximately 20M elements for ~0.01 sec runtime
    x = (ZVEC*)malloc(sizeof(ZVEC));
    x->dim = dim;
    x->max_dim = dim;
    x->ve = (complex*)malloc(dim * sizeof(complex));
    
    for (int j = 0; j < dim; j++) {
        x->ve[j].re = 1.0;
        x->ve[j].im = 1.0;
    }
    
    i = 0;
    sum = 0.0;
}