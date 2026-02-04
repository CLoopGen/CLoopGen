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
for (i = 0; i < 3; i++) {
    int j = i;
    c->c[j].real = s1 * a->c[j].real + s2 * b->c[j].real;
    c->c[j].imag = s1 * a->c[j].imag + s2 * b->c[j].imag;
}
}
