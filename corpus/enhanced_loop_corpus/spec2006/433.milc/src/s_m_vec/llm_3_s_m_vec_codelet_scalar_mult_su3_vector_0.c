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
    // Variant 2: Consecutive memory access using pointer arithmetic to flatten struct access
    complex *aptr = &(a->c[0]);
    complex *cptr = &(c->c[0]);
    for (i = 0; i < 6; i++) {
        if (i % 2 == 0) {
            cptr[i/2].real = s * aptr[i/2].real;
        } else {
            cptr[i/2].imag = s * aptr[i/2].imag;
        }
    }
}
