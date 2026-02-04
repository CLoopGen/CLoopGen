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
for (n = 0; n < 8; n++) {
    at = a + (n % 4);
    switch (n % 4) {
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
        ar = at->e[i][0].real;
        ai = at->e[i][0].imag;
        br = b->c[0].real;
        bi = b->c[0].imag;
        cr = ar * br - ai * bi;
        ci = ar * bi + ai * br;
        
        ar = at->e[i][1].real;
        ai = at->e[i][1].imag;
        br = b->c[1].real;
        bi = b->c[1].imag;
        cr += ar * br - ai * bi;
        ci += ar * bi + ai * br;

        ar = at->e[i][2].real;
        ai = at->e[i][2].imag;
        br = b->c[2].real;
        bi = b->c[2].imag;
        cr += ar * br - ai * bi;
        ci += ar * bi + ai * br;

        c->c[i].real += cr;
        c->c[i].imag += ci;
    }
}
}
