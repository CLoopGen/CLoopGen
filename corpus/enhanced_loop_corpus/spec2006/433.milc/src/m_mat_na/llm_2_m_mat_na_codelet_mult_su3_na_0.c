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
for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++) {
        cr = 0.0;
        ci = 0.0;
        for (int k = 0; k < 3; k++) {
            ar = a->e[i][k].real;
            ai = a->e[i][k].imag;
            br = b->e[j][k].real;
            bi = b->e[j][k].imag;
            t = ar * br - ai * bi;
            cr += t;
            t = ar * bi + ai * br;
            ci += t;
        }
        c->e[i][j].real = cr;
        c->e[i][j].imag = ci;
    }
}
