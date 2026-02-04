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
extern su3_vector *c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i >= 0; i--) {
    c->c[i].real = a->c[i].real - b->c[i].real;
    c->c[i].imag = a->c[i].imag - b->c[i].imag;
}
}
