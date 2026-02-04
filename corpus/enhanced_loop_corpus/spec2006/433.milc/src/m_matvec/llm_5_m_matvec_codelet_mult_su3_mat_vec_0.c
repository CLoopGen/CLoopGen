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
    ar = a->e[i][0].real;
    ai = a->e[i][0].imag;
    br = b->c[0].real;
    bi = b->c[0].imag;
    cr = ar * br;
    t = ai * bi;
    cr -= t;
    ci = ar * bi;
    t = ai * br;
    ci += t;

    if (cr > -1.0 && ci < 1.0) {
        ar = a->e[i][1].real;
        ai = a->e[i][1].imag;
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
    }

    ar = a->e[i][2].real;
    ai = a->e[i][2].imag;
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

    c->c[i].real = cr;
    c->c[i].imag = ci;
}
}
