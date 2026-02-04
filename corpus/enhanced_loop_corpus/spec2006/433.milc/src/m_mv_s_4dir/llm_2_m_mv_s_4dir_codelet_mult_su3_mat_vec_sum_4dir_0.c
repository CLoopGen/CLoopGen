#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

extern su3_vector *c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (forward and wrap-around)
    // Access pattern: 0, 2, 1 (covers all 3 elements using strided logic with modulo)
    for (int j = 0; j < 3; j++) {
        int i = (j * 2) % 3;  // Stride of 2 with modulo to stay in bounds
        c->c[i].real = 0.;
        c->c[i].imag = 0.;
    }
}
