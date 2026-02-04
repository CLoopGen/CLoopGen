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
double *a_real = &a->e[0][0].real;
double *a_imag = &a->e[0][0].imag;
double *b_real = &b->e[0][0].real;
double *b_imag = &b->e[0][0].imag;
double *c_real = &c->e[0][0].real;
double *c_imag = &c->e[0][0].imag;

for (i = 0; i < 9; i++) {
    int row = i / 3;
    int col = i % 3;
    cr = 0.0;
    ci = 0.0;
    for (int k = 0; k < 3; k++) {
        int a_idx = row * 3 + k;
        int b_idx = col * 3 + k;
        ar = a_real[a_idx];
        ai = a_imag[a_idx];
        br = b_real[b_idx];
        bi = b_imag[b_idx];
        cr += ar * br - ai * bi;
        ci += ar * bi + ai * br;
    }
    c_real[i] = cr;
    c_imag[i] = ci;
}
}
