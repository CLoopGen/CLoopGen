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
for (i = 0; i < 9; i += 3) {
    int idx = i / 3;
    c->c[idx].real = s1 * a->c[idx].real + s2 * b->c[idx].real;
    c->c[idx].imag = s1 * a->c[idx].imag + s2 * b->c[idx].imag;
}
}
