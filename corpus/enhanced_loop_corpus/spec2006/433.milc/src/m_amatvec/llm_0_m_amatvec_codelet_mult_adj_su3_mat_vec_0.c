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
    double cr = 0.0, ci = 0.0;
    for (int j = 0; j < 3; j++) {
        double ar = a->e[j][i].real;
        double ai = a->e[j][i].imag;
        double br = b->c[j].real;
        double bi = b->c[j].imag;
        double t1 = ar * br - ai * bi;
        double t2 = ar * bi + ai * br;
        cr += t1;
        ci += t2;
    }
    c->c[i].real = cr;
    c->c[i].imag = ci;
}
}
