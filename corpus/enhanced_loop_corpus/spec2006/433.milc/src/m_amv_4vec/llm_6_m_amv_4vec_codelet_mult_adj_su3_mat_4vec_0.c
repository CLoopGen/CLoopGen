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
    su3_vector temp_c;
    double br0 = b->c[0].real, bi0 = b->c[0].imag;
    double br1 = b->c[1].real, bi1 = b->c[1].imag;
    double br2 = b->c[2].real, bi2 = b->c[2].imag;

    double c0r = 0.0, c0i = 0.0;
    double c1r = 0.0, c1i = 0.0;
    double c2r = 0.0, c2i = 0.0;

    for (int i = 0; i < 3; i++) {
        double ar0r = a->e[i][0].real, ar0i = a->e[i][0].imag;
        double ar1r = a->e[i][1].real, ar1i = a->e[i][1].imag;
        double ar2r = a->e[i][2].real, ar2i = a->e[i][2].imag;

        double br = *((double*)&b->c[i] + 0);
        double bi = *((double*)&b->c[i] + 1);

        c0r += ar0r * br - ar0i * bi;
        c0i += ar0r * bi + ar0i * br;
        c1r += ar1r * br - ar1i * bi;
        c1i += ar1r * bi + ar1i * br;
        c2r += ar2r * br - ar2i * bi;
        c2i += ar2r * bi + ar2i * br;
    }

    temp_c.c[0].real = c0r; temp_c.c[0].imag = c0i;
    temp_c.c[1].real = c1r; temp_c.c[1].imag = c1i;
    temp_c.c[2].real = c2r; temp_c.c[2].imag = c2i;

    *c = temp_c;
}
}
