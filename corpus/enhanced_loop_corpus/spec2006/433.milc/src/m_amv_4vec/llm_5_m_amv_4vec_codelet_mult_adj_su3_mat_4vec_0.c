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
extern su3_vector *cc[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < 4; n++ , a++) {
    c = cc[n];
    br = b->c[0].real;
    bi = b->c[0].imag;
    a0 = a->e[0][0].real;
    a1 = a->e[0][1].real;
    a2 = a->e[0][2].real;
    c0r = a0 * br;
    c1r = a1 * br;
    c2r = a2 * br;
    c0i = a0 * bi;
    c1i = a1 * bi;
    c2i = a2 * bi;
    a0 = a->e[0][0].imag;
    a1 = a->e[0][1].imag;
    a2 = a->e[0][2].imag;
    if (a0 != 0.0 || a1 != 0.0 || a2 != 0.0) {
        c0r += a0 * bi;
        c1r += a1 * bi;
        c2r += a2 * bi;
        c0i -= a0 * br;
        c1i -= a1 * br;
        c2i -= a2 * br;
    }
    br = b->c[1].real;
    bi = b->c[1].imag;
    a0 = a->e[1][0].real;
    a1 = a->e[1][1].real;
    a2 = a->e[1][2].real;
    c0r += a0 * br;
    c1r += a1 * br;
    c2r += a2 * br;
    c0i += a0 * bi;
    c1i += a1 * bi;
    c2i += a2 * bi;
    a0 = a->e[1][0].imag;
    a1 = a->e[1][1].imag;
    a2 = a->e[1][2].imag;
    if (a0 != 0.0 || a1 != 0.0 || a2 != 0.0) {
        c0r += a0 * bi;
        c1r += a1 * bi;
        c2r += a2 * bi;
        c0i -= a0 * br;
        c1i -= a1 * br;
        c2i -= a2 * br;
    }
    br = b->c[2].real;
    bi = b->c[2].imag;
    a0 = a->e[2][0].real;
    a1 = a->e[2][1].real;
    a2 = a->e[2][2].real;
    c0r += a0 * br;
    c1r += a1 * br;
    c2r += a2 * br;
    c0i += a0 * bi;
    c1i += a1 * bi;
    c2i += a2 * bi;
    a0 = a->e[2][0].imag;
    a1 = a->e[2][1].imag;
    a2 = a->e[2][2].imag;
    if (a0 != 0.0 || a1 != 0.0 || a2 != 0.0) {
        c0r += a0 * bi;
        c1r += a1 * bi;
        c2r += a2 * bi;
        c0i -= a0 * br;
        c1i -= a1 * br;
        c2i -= a2 * br;
    }
    c->c[0].real = c0r;
    c->c[0].imag = c0i;
    c->c[1].real = c1r;
    c->c[1].imag = c1i;
    c->c[2].real = c2r;
    c->c[2].imag = c2i;
}
}
