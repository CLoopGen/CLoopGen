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
for (n = 0; n < 4; n++ , a++ , c++) {
    c0r = c1r = c2r = 0.0;
    c0i = c1i = c2i = 0.0;

    for (int i = 0; i < 3; i++) {
        br = b->c[i].real;
        bi = b->c[i].imag;

        if (br == 0.0 && bi == 0.0) {
            continue;
        }

        a0 = a->e[i][0].real;
        a1 = a->e[i][1].real;
        a2 = a->e[i][2].real;
        c0r += a0 * br;
        c1r += a1 * br;
        c2r += a2 * br;
        c0i += a0 * bi;
        c1i += a1 * bi;
        c2i += a2 * bi;

        a0 = a->e[i][0].imag;
        a1 = a->e[i][1].imag;
        a2 = a->e[i][2].imag;
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
