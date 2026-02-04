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
for (i = 0; i < 6; i++) {
    int idx = i % 3;
    {
        (c->c[idx]).real = (a->c[idx]).real + (b->c[idx]).real + (a->c[idx]).imag - (b->c[idx]).imag;
        (c->c[idx]).imag = (a->c[idx]).imag + (b->c[idx]).imag + (a->c[idx]).real - (b->c[idx]).real;
    }
}
}
