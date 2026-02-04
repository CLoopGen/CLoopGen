#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_vector *a;
extern su3_vector *b;
extern su3_matrix *c;
extern int i;
extern int j;
extern double tmp;
extern double tmp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 9; i++) {
    int ii = i / 3;
    int jj = i % 3;
    tmp2 = a->c[ii].real * b->c[jj].real;
    tmp = a->c[ii].imag * b->c[jj].imag;
    c->e[ii][jj].real = tmp + tmp2;
    tmp2 = a->c[ii].real * b->c[jj].imag;
    tmp = a->c[ii].imag * b->c[jj].real;
    c->e[ii][jj].imag = tmp - tmp2;
}
}
