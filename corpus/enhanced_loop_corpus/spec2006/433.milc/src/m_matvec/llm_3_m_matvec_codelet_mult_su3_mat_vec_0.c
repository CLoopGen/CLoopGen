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
int indices[3] = {2, 1, 0}; // Reverse access pattern
for (i = 0; i < 3; i++) {
    cr = 0.0;
    ci = 0.0;
    for (int j = 0; j < 3; j++) {
        int idx = indices[j]; // Indirect (permuted) access to matrix/vector elements
        ar = a->e[i][idx].real;
        ai = a->e[i][idx].imag;
        br = b->c[idx].real;
        bi = b->c[idx].imag;
        double real_part = ar * br - ai * bi;
        double imag_part = ar * bi + ai * br;
        cr += real_part;
        ci += imag_part;
    }
    c->c[i].real = cr;
    c->c[i].imag = ci;
}
}
