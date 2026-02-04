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
extern double s;
extern su3_vector *c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (reverse order with stride of 1, accessing every element backwards)
    for (i = 2; i >= 0; i--) {
        c->c[i].real = s * a->c[i].real;
        c->c[i].imag = s * a->c[i].imag;
    }
}
