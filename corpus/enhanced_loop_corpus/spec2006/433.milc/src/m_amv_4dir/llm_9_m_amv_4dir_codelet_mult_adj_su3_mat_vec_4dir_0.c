#include <stdio.h>

#include <inttypes.h>

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

extern int n;
extern double c0r;
extern double c0i;
extern double c1r;
extern double c1i;
extern double c2r;
extern double c2i;
extern double br;
extern double bi;
extern double a0;
extern double a1;
extern double a2;
extern su3_matrix *a;
extern su3_vector *b;
extern su3_vector *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: only first row of matrix applied
for (n = 0; n < 4; n++, a++, c++) {
    br = b->c[0].real;
    bi = b->c[0].imag;
    a0 = a->e[0][0].real;
    a1 = a->e[0][1].real;
    a2 = a->e[0][2].real;
    c0r = a0 * br - a->e[0][0].imag * bi;
    c1r = a1 * br - a->e[0][1].imag * bi;
    c2r = a2 * br - a->e[0][2].imag * bi;
    c0i = a0 * bi + a->e[0][0].imag * br;
    c1i = a1 * bi + a->e[0][1].imag * br;
    c2i = a2 * bi + a->e[0][2].imag * br;

    // Skip second and third rows — partial matrix-vector multiply
    c->c[0].real = c0r;
    c->c[0].imag = c0i;
    c->c[1].real = c1r;
    c->c[1].imag = c1i;
    c->c[2].real = c2r;
    c->c[2].imag = c2i;
}
}
