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
    double temp_real[3], temp_imag[3];
    for (i = 0; i < 3; i++) {
        temp_real[i] = s1 * a->c[i].real;
        temp_imag[i] = s1 * a->c[i].imag;
    }
    for (i = 0; i < 3; i++) {
        c->c[i].real = temp_real[i] + s2 * b->c[i].real;
        c->c[i].imag = temp_imag[i] + s2 * b->c[i].imag;
    }
}
