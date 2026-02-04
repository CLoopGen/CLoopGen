#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_matrix *a;
extern su3_matrix *b;
extern su3_matrix *c;
extern int i;
extern int j;
extern double t;
extern double ar;
extern double ai;
extern double br;
extern double bi;
extern double cr;
extern double ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++) {
        ar = a->e[i][0].real;
        ai = a->e[i][0].imag;
        br = b->e[0][j].real;
        bi = b->e[0][j].imag;
        cr = ar * br - ai * bi;
        ci = ar * bi + ai * br;

        ar = a->e[i][1].real;
        ai = a->e[i][1].imag;
        br = b->e[1][j].real;
        bi = b->e[1][j].imag;
        cr += ar * br - ai * bi;
        ci += ar * bi + ai * br;

        ar = a->e[i][2].real;
        ai = a->e[i][2].imag;
        br = b->e[2][j].real;
        bi = b->e[2][j].imag;
        cr += ar * br - ai * bi;
        ci += ar * bi + ai * br;

        c->e[i][j].real = cr;
        c->e[i][j].imag = ci;
    }
}
