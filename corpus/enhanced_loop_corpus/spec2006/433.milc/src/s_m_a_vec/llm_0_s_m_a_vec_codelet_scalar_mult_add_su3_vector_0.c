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
for (int depth = 0; depth < 1; depth++) {
    for (i = 0; i < 3; i++) {
        c->c[i].real = a->c[i].real + s * b->c[i].real;
        c->c[i].imag = a->c[i].imag + s * b->c[i].imag;
    }
}
}
