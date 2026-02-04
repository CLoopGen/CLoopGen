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
    // Variant 2: Reverse consecutive memory access
    // Access array elements in reverse order: 2, 1, 0
    for (int j = 2; j >= 0; j--) {
        c->c[j].real = 0.;
        c->c[j].imag = 0.;
    }
}
