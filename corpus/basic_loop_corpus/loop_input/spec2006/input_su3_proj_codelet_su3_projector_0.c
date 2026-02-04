#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

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

su3_vector *a;
su3_vector *b;
su3_matrix *c;
int i;
int j;
double tmp;
double tmp2;

void init_vars() {
    a = (su3_vector*)malloc(sizeof(su3_vector));
    b = (su3_vector*)malloc(sizeof(su3_vector));
    c = (su3_matrix*)malloc(sizeof(su3_matrix));

    for (int ii = 0; ii < 3; ii++) {
        for (int jj = 0; jj < 3; jj++) {
            a->c[ii].real = 1.0 + ii * 0.1;
            a->c[ii].imag = 0.5 + ii * 0.05;
            b->c[jj].real = 2.0 + jj * 0.2;
            b->c[jj].imag = 1.5 + jj * 0.07;
            c->e[ii][jj].real = 0.0;
            c->e[ii][jj].imag = 0.0;
        }
    }

    i = 0;
    j = 0;
    tmp = 0.0;
    tmp2 = 0.0;
}