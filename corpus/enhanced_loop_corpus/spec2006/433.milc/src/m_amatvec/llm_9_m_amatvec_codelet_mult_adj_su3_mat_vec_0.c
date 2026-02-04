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
for (i = 0; i < 6; i += 2) {
    int j = i % 3;
    ar = a->e[0][j].real;
    ai = a->e[0][j].imag;
    br = b->c[0].real;
    bi = b->c[0].imag;
    cr = ar * br;
    t = ai * bi;
    cr += t;
    ci = ar * bi;
    t = ai * br;
    ci -= t;
    ar = a->e[1][j].real;
    ai = a->e[1][j].imag;
    br = b->c[1].real;
    bi = b->c[1].imag;
    t = ar * br;
    cr += t;
    t = ai * bi;
    cr += t;
    t = ar * bi;
    ci += t;
    t = ai * br;
    ci -= t;
    ar = a->e[2][j].real;
    ai = a->e[2][j].imag;
    br = b->c[2].real;
    bi = b->c[2].imag;
    t = ar * br;
    cr += t;
    t = ai * bi;
    cr += t;
    t = ar * bi;
    ci += t;
    t = ai * br;
    ci -= t;
    c->c[j].real = cr;
    c->c[j].imag = ci;

    if (i + 1 < 6) {
        j = (i + 1) % 3;
        ar = a->e[0][j].real;
        ai = a->e[0][j].imag;
        br = b->c[0].real;
        bi = b->c[0].imag;
        cr = ar * br;
        t = ai * bi;
        cr += t;
        ci = ar * bi;
        t = ai * br;
        ci -= t;
        ar = a->e[1][j].real;
        ai = a->e[1][j].imag;
        br = b->c[1].real;
        bi = b->c[1].imag;
        t = ar * br;
        cr += t;
        t = ai * bi;
        cr += t;
        t = ar * bi;
        ci += t;
        t = ai * br;
        ci -= t;
        ar = a->e[2][j].real;
        ai = a->e[2][j].imag;
        br = b->c[2].real;
        bi = b->c[2].imag;
        t = ar * br;
        cr += t;
        t = ai * bi;
        cr += t;
        t = ar * bi;
        ci += t;
        t = ai * br;
        ci -= t;
        c->c[j].real = cr;
        c->c[j].imag = ci;
    }
}
}
