#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

su3_matrix *a;
su3_matrix *b;
su3_matrix *c;
int i;
int j;

void init_vars() {
    a = (su3_matrix*)malloc(sizeof(su3_matrix));
    b = (su3_matrix*)malloc(sizeof(su3_matrix));
    c = (su3_matrix*)malloc(sizeof(su3_matrix));

    for (int ii = 0; ii < 3; ii++) {
        for (int jj = 0; jj < 3; jj++) {
            (a->e[ii][jj]).real = 1.0;
            (a->e[ii][jj]).imag = 0.5;
            (b->e[ii][jj]).real = 0.5;
            (b->e[ii][jj]).imag = 0.25;
            (c->e[ii][jj]).real = 0.0;
            (c->e[ii][jj]).imag = 0.0;
        }
    }

    i = 0;
    j = 0;
}