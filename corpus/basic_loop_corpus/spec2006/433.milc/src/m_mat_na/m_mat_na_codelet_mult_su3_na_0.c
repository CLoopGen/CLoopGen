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
        ar = a->e[i][0].real;
        ai = a->e[i][0].imag;
        br = b->e[j][0].real;
        bi = b->e[j][0].imag;
        cr = ar * br;
        t = ai * bi;
        cr += t;
        ci = ai * br;
        t = ar * bi;
        ci -= t;
        ar = a->e[i][1].real;
        ai = a->e[i][1].imag;
        br = b->e[j][1].real;
        bi = b->e[j][1].imag;
        t = ar * br;
        cr += t;
        t = ai * bi;
        cr += t;
        t = ar * bi;
        ci -= t;
        t = ai * br;
        ci += t;
        ar = a->e[i][2].real;
        ai = a->e[i][2].imag;
        br = b->e[j][2].real;
        bi = b->e[j][2].imag;
        t = ar * br;
        cr += t;
        t = ai * bi;
        cr += t;
        t = ar * bi;
        ci -= t;
        t = ai * br;
        ci += t;
        c->e[i][j].real = cr;
        c->e[i][j].imag = ci;
    }

}
