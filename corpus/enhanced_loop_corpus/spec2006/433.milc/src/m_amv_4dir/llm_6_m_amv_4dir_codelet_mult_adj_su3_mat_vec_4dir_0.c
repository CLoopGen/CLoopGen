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
    double temp_c0r = 0.0, temp_c0i = 0.0;
    double temp_c1r = 0.0, temp_c1i = 0.0;
    double temp_c2r = 0.0, temp_c2i = 0.0;

    for (int i = 0; i < 3; i++) {
        double br = b->c[i].real;
        double bi = b->c[i].imag;

        double a0r = a->e[i][0].real;
        double a1r = a->e[i][1].real;
        double a2r = a->e[i][2].real;
        double a0i = a->e[i][0].imag;
        double a1i = a->e[i][1].imag;
        double a2i = a->e[i][2].imag;

        temp_c0r += a0r * br - a0i * bi;
        temp_c0i += a0r * bi + a0i * br;
        temp_c1r += a1r * br - a1i * bi;
        temp_c1i += a1r * bi + a1i * br;
        temp_c2r += a2r * br - a2i * bi;
        temp_c2i += a2r * bi + a2i * br;
    }

    c->c[0].real = temp_c0r;
    c->c[0].imag = temp_c0i;
    c->c[1].real = temp_c1r;
    c->c[1].imag = temp_c1i;
    c->c[2].real = temp_c2r;
    c->c[2].imag = temp_c2i;
}
}
