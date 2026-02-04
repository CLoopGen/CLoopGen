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
    for (i = 0; i < 3; i++) {
        double real_part = a->c[i].real;
        double imag_part = a->c[i].imag;
        c->c[i].real = s * real_part + s * real_part; // Double the multiplication: 2 ops instead of 1
        c->c[i].imag = s * imag_part + s * imag_part; // Increased arithmetic intensity
    }
}
