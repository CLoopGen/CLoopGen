#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

extern su3_vector *a;
extern su3_vector *b;
extern double s;
extern su3_vector *c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double accum_real = 0.0, accum_imag = 0.0;
    for (i = 0; i < 3; i++) {
        accum_real += a->c[i].real + s * b->c[i].real;
        accum_imag += a->c[i].imag + s * b->c[i].imag;
        c->c[i].real = accum_real;
        c->c[i].imag = accum_imag;
    }
}
