#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_matrix *a;
extern su3_matrix *b;
extern double s;
extern su3_matrix *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i++) {
    c->e[i][0].real = a->e[i][0].real - s * b->e[i][0].real;
    c->e[i][0].imag = a->e[i][0].imag - s * b->e[i][0].imag;
    c->e[i][1].real = a->e[i][1].real - s * b->e[i][1].real;
    c->e[i][1].imag = a->e[i][1].imag - s * b->e[i][1].imag;
    c->e[i][2].real = a->e[i][2].real - s * b->e[i][2].real;
    c->e[i][2].imag = a->e[i][2].imag - s * b->e[i][2].imag;
}
}
