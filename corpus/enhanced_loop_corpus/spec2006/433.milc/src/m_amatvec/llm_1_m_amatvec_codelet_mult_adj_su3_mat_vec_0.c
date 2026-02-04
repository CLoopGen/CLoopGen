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
for (i = 0; i < 1; i++) {
    for (int k = 0; k < 3; k++) {
        double cr = 0.0, ci = 0.0;
        for (int j = 0; j < 3; j++) {
            double ar = a->e[j][k].real;
            double ai = a->e[j][k].imag;
            double br = b->c[j].real;
            double bi = b->c[j].imag;
            cr += ar * br - ai * bi;
            ci += ar * bi + ai * br;
        }
        c->c[k].real = cr;
        c->c[k].imag = ci;
    }
}
}
