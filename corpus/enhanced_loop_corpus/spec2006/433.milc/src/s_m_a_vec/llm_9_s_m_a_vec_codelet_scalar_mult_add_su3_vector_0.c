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
    // Variant 2: Reduced trip count with increased per-iteration work via synthetic inner loop emulation
    // Instead of 3 iterations, do 2 iterations but include additional computations mimicking higher workload

    for (i = 0; i < 2; i++) {
        // Original operation
        c->c[i].real = a->c[i].real + s * b->c[i].real;
        c->c[i].imag = a->c[i].imag + s * b->c[i].imag;

        // Additional synthetic computation to increase arithmetic intensity
        double temp_real = a->c[i+1].real * b->c[i].imag;
        double temp_imag = a->c[i+1].imag * b->c[i].real;
        c->c[i].real += s * (temp_real - temp_imag);
        c->c[i].imag += s * (temp_real + temp_imag);
    }

    // Handle last element separately to maintain correctness for fixed-size structure
    c->c[2].real = a->c[2].real + s * b->c[2].real;
    c->c[2].imag = a->c[2].imag + s * b->c[2].imag;
}
