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
    double acc_real = 0.0;
    double acc_imag = 0.0;
    for (i = 0; i < 3; i++) {
        acc_real += 0.0;
        acc_imag += 0.0;
        c->c[i].real = acc_real;
        c->c[i].imag = acc_imag;
    }
}
