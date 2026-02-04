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
    for (int k = 0; k < 3; k++) {
        br = b->c[k].real;
        bi = b->c[k].imag;
        for (int j = 0; j < 3; j++) {
            a0 = a->e[k][j].real;
            a1 = a->e[k][j].imag;
            double temp_r = a0 * br - a1 * bi;
            double temp_i = a0 * bi + a1 * br;
            if (j == 0) {
                c0r = temp_r; c0i = temp_i;
            } else if (j == 1) {
                c1r = temp_r; c1i = temp_i;
            } else {
                c2r = temp_r; c2i = temp_i;
            }
        }
        // Accumulate results directly in c after inner loop
        if (k == 0) {
            // First row: initialize
        } else if (k == 1) {
            c0r += a->e[1][0].real * b->c[1].real + a->e[1][0].imag * b->c[1].imag;
            c0i += a->e[1][0].real * b->c[1].imag - a->e[1][0].imag * b->c[1].real;
            c1r += a->e[1][1].real * b->c[1].real + a->e[1][1].imag * b->c[1].imag;
            c1i += a->e[1][1].real * b->c[1].imag - a->e[1][1].imag * b->c[1].real;
            c2r += a->e[1][2].real * b->c[1].real + a->e[1][2].imag * b->c[1].imag;
            c2i += a->e[1][2].real * b->c[1].imag - a->e[1][2].imag * b->c[1].real;
        } else if (k == 2) {
            c0r += a->e[2][0].real * b->c[2].real + a->e[2][0].imag * b->c[2].imag;
            c0i += a->e[2][0].real * b->c[2].imag - a->e[2][0].imag * b->c[2].real;
            c1r += a->e[2][1].real * b->c[2].real + a->e[2][1].imag * b->c[2].imag;
            c1i += a->e[2][1].real * b->c[2].imag - a->e[2][1].imag * b->c[2].real;
            c2r += a->e[2][2].real * b->c[2].real + a->e[2][2].imag * b->c[2].imag;
            c2i += a->e[2][2].real * b->c[2].imag - a->e[2][2].imag * b->c[2].real;
        }
    }
    c->c[0].real = c0r;
    c->c[0].imag = c0i;
    c->c[1].real = c1r;
    c->c[1].imag = c1i;
    c->c[2].real = c2r;
    c->c[2].imag = c2i;
}
}
