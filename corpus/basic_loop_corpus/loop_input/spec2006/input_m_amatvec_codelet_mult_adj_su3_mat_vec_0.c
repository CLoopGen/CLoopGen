#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

typedef struct {
    complex c[3];
} su3_vector;

su3_matrix *a;
su3_vector *b;
su3_vector *c;
int i;
double t;
double ar;
double ai;
double br;
double bi;
double cr;
double ci;

void init_vars() {
    // Allocate memory for a, b, and c
    a = (su3_matrix*)malloc(sizeof(su3_matrix));
    b = (su3_vector*)malloc(sizeof(su3_vector));
    c = (su3_vector*)malloc(sizeof(su3_vector));

    // Initialize matrix a with non-zero values to avoid trivial computation
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            double angle = (row + 1) * (col + 1);
            a->e[row][col].real = cos(angle);
            a->e[row][col].imag = sin(angle);
        }
    }

    // Initialize vector b
    for (int idx = 0; idx < 3; idx++) {
        b->c[idx].real = cos(idx + 1);
        b->c[idx].imag = sin(idx + 1);
    }

    // Initialize result vector c to zero
    for (int idx = 0; idx < 3; idx++) {
        c->c[idx].real = 0.0;
        c->c[idx].imag = 0.0;
    }

    // Initialize scalars
    t = 0.0;
    ar = 0.0;
    ai = 0.0;
    br = 0.0;
    bi = 0.0;
    cr = 0.0;
    ci = 0.0;
    i = 0;
}