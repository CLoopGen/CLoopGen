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
extern su3_vector *b0;
extern su3_vector *b1;
extern su3_vector *b2;
extern su3_vector *b3;
extern su3_vector *c;
extern int i;
extern int n;
extern su3_matrix *at;
extern su3_vector *b;
extern double t;
extern double ar;
extern double ai;
extern double br;
extern double bi;
extern double cr;
extern double ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < 4; n++) {
    at = a + n;
    if (n == 0) {
        b = b0;
    } else if (n == 1) {
        b = b1;
    } else if (n == 2) {
        b = b2;
    } else if (n == 3) {
        b = b3;
    } else {
        continue;
    }
    for (i = 0; i < 3; i++) {
        ar = at->e[i][0].real;
        ai = at->e[i][0].imag;
        br = b->c[0].real;
        bi = b->c[0].imag;
        cr = ar * br;
        t = ai * bi;
        cr -= t;
        ci = ar * bi;
        t = ai * br;
        ci += t;
        ar = at->e[i][1].real;
        ai = at->e[i][1].imag;
        br = b->c[1].real;
        bi = b->c[1].imag;
        t = ar * br;
        cr += t;
        t = ai * bi;
        cr -= t;
        t = ar * bi;
        ci += t;
        t = ai * br;
        ci += t;
        ar = at->e[i][2].real;
        ai = at->e[i][2].imag;
        br = b->c[2].real;
        bi = b->c[2].imag;
        t = ar * br;
        cr += t;
        t = ai * bi;
        cr -= t;
        t = ar * bi;
        ci += t;
        t = ai * br;
        ci += t;
        c->c[i].real += cr;
        c->c[i].imag += ci;
    }
}
}
