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
for (i = 0; i < 3; i++) {
    if (!(a->c[i]).real > (b->c[i]).real) {
        (c->c[i]).real = (a->c[i]).real - (b->c[i]).real;
        (c->c[i]).imag = (a->c[i]).imag - (b->c[i]).imag;
    } else {
        (c->c[i]).real = 0.0;
        (c->c[i]).imag = 0.0;
    }
}
}
