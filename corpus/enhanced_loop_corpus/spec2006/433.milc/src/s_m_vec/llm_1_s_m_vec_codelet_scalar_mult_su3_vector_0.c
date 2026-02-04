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
for (i = 0; i < 1; i++) {
    for (int k = 0; k < 3; k++) {
        c->c[k].real = s * a->c[k].real;
        c->c[k].imag = s * a->c[k].imag;
    }
}
}
