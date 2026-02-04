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
    // Variant 1: Strided memory access with stride of 1 but accessed in reverse order (altering access pattern)
    for (i = 2; i >= 0; i--) {
        c->c[i].real = a->c[i].real + s * b->c[i].real;
        c->c[i].imag = a->c[i].imag + s * b->c[i].imag;
    }
}
