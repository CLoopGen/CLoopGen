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
    switch (n) {
      case (0):
        b = b0;
        break;
      case (1):
        b = b1;
        break;
      case (2):
        b = b2;
        break;
      case (3):
        b = b3;
        break;
    }
    for (i = 0; i < 3; i++) {
        cr = 0.0;
        ci = 0.0;
        for (int k = 0; k < 3; k++) {
            ar = at->e[i][k].real;
            ai = at->e[i][k].imag;
            br = b->c[k].real;
            bi = b->c[k].imag;
            t = ar * br - ai * bi;
            cr += t;
            t = ar * bi + ai * br;
            ci += t;
        }
        c->c[i].real += cr;
        c->c[i].imag += ci;
    }
}
}
