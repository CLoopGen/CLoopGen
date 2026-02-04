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
extern double s1;
extern su3_vector *b;
extern double s2;
extern su3_vector *c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified scalar reuse and explicit strength reduction
    // Precompute scaled values outside the loop to reduce arithmetic operations inside
    double s1_real, s1_imag, s2_real, s2_imag;
    for (i = 0; i < 1; i++) {  // Reduce effective trip count logic by fusing all computations in one iteration
        s1_real = s1 * a->c[0].real;
        s1_imag = s1 * a->c[0].imag;
        s2_real = s2 * b->c[0].real;
        s2_imag = s2 * b->c[0].imag;
        c->c[0].real = s1_real + s2_real;
        c->c[0].imag = s1_imag + s2_imag;

        s1_real = s1 * a->c[1].real;
        s1_imag = s1 * a->c[1].imag;
        s2_real = s2 * b->c[1].real;
        s2_imag = s2 * b->c[1].imag;
        c->c[1].real = s1_real + s2_real;
        c->c[1].imag = s1_imag + s2_imag;

        s1_real = s1 * a->c[2].real;
        s1_imag = s1 * a->c[2].imag;
        s2_real = s2 * b->c[2].real;
        s2_imag = s2 * b->c[2].imag;
        c->c[2].real = s1_real + s2_real;
        c->c[2].imag = s1_imag + s2_imag;
    }
}
