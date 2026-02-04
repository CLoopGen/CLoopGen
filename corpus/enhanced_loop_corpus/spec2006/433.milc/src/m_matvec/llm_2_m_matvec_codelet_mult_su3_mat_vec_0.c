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
    for (int j = 0; j < 3; j++) {
        ar = a->e[i][j].real;
        ai = a->e[i][j].imag;
        br = b->c[j].real;
        bi = b->c[j].imag;
        t = ar * br - ai * bi;
        cr += t;
        t = ar * bi + ai * br;
        ci += t;
    }
    c->c[i].real = cr;
    c->c[i].imag = ci;
}
}
