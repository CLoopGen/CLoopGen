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
    double temp_real[3];
    double temp_imag[3];
    for (i = 0; i < 3; i++) {
        temp_real[i] = 0.;
        temp_imag[i] = 0.;
    }
    for (i = 0; i < 3; i++) {
        c->c[i].real = temp_real[i];
        c->c[i].imag = temp_imag[i];
    }
}
