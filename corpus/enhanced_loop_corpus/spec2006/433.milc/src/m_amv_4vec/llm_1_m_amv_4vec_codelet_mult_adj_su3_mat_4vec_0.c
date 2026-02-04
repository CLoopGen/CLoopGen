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
for (n = 0; n < 4; n++) {
    c = cc[n];
    c0r = c1r = c2r = 0.0;
    c0i = c1i = c2i = 0.0;
    for (int i = 0; i < 3; i++) {
        br = b->c[i].real;
        bi = b->c[i].imag;
        for (int j = 0; j < 3; j++) {
            a0 = a[n].e[i][j].real;
            a1 = a[n].e[i][j].imag;
            double prod_r = a0 * br - a1 * bi;
            double prod_i = a0 * bi + a1 * br;
            if (j == 0) {
                c0r += prod_r; c0i += prod_i;
            } else if (j == 1) {
                c1r += prod_r; c1i += prod_i;
            } else {
                c2r += prod_r; c2i += prod_i;
            }
        }
    }
    c->c[0].real = c0r;
    c->c[0].imag = c0i;
    c->c[1].real = c1r;
    c->c[1].imag = c1i;
    c->c[2].real = c2r;
    c->c[2].imag = c2i;
    a++;
}
}
