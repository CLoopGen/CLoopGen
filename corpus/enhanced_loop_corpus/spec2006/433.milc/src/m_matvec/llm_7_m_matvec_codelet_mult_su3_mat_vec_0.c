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

extern su3_matrix *a;
extern su3_vector *b;
extern su3_vector *c;
extern int i;
extern double t;
extern double ar;
extern double ai;
extern double br;
extern double bi;
extern double cr;
extern double ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        cr = 0.0;
        ci = 0.0;
        ar = a->e[i][0].real;
        ai = a->e[i][0].imag;
        br = b->c[0].real;
        bi = b->c[0].imag;
        cr += ar * br - ai * bi;
        ci += ar * bi + ai * br;

        ar = a->e[i][1].real;
        ai = a->e[i][1].imag;
        br = b->c[1].real;
        bi = b->c[1].imag;
        cr += ar * br - ai * bi;
        ci += ar * bi + ai * br;

        ar = a->e[i][2].real;
        ai = a->e[i][2].imag;
        br = b->c[2].real;
        bi = b->c[2].imag;
        cr += ar * br - ai * bi;
        ci += ar * bi + ai * br;

        c->c[i].real = cr;
        c->c[i].imag = ci;
    }
}
