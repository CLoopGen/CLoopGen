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
for (n = 0; n < 2; n++) {
    at = a + n * 2;
    if (n == 0) {
        b = b0;
    } else {
        b = b2;
    }
    for (i = 0; i < 3; i++) {
        cr = 0.0;
        ci = 0.0;
        for (int j = 0; j < 3; j++) {
            ar = at->e[i][j].real;
            ai = at->e[i][j].imag;
            br = b->c[j].real;
            bi = b->c[j].imag;
            cr += ar * br - ai * bi;
            ci += ar * bi + ai * br;
        }
        c->c[i].real += cr;
        c->c[i].imag += ci;
        
        cr = 0.0;
        ci = 0.0;
        ar = (at+1)->e[i][0].real;
        ai = (at+1)->e[i][0].imag;
        br = (b == b0 ? b1 : b3)->c[0].real;
        bi = (b == b0 ? b1 : b3)->c[0].imag;
        cr += ar * br - ai * bi;
        ci += ar * bi + ai * br;

        ar = (at+1)->e[i][1].real;
        ai = (at+1)->e[i][1].imag;
        br = (b == b0 ? b1 : b3)->c[1].real;
        bi = (b == b0 ? b1 : b3)->c[1].imag;
        cr += ar * br - ai * bi;
        ci += ar * bi + ai * br;

        ar = (at+1)->e[i][2].real;
        ai = (at+1)->e[i][2].imag;
        br = (b == b0 ? b1 : b3)->c[2].real;
        bi = (b == b0 ? b1 : b3)->c[2].imag;
        cr += ar * br - ai * bi;
        ci += ar * bi + ai * br;

        c->c[i].real += cr;
        c->c[i].imag += ci;
    }
}
}
