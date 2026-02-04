#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_vector *a;
extern su3_vector *b;
extern su3_matrix *c;
extern int i;
extern int j;
extern double tmp;
extern double tmp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i++) {
    tmp2 = a->c[i].real * b->c[0].real;
    tmp = a->c[i].imag * b->c[0].imag;
    c->e[i][0].real = tmp + tmp2;
    tmp2 = a->c[i].real * b->c[0].imag;
    tmp = a->c[i].imag * b->c[0].real;
    c->e[i][0].imag = tmp - tmp2;
}
for (i = 0; i < 3; i++) {
    tmp2 = a->c[i].real * b->c[1].real;
    tmp = a->c[i].imag * b->c[1].imag;
    c->e[i][1].real = tmp + tmp2;
    tmp2 = a->c[i].real * b->c[1].imag;
    tmp = a->c[i].imag * b->c[1].real;
    c->e[i][1].imag = tmp - tmp2;
}
for (i = 0; i < 3; i++) {
    tmp2 = a->c[i].real * b->c[2].real;
    tmp = a->c[i].imag * b->c[2].imag;
    c->e[i][2].real = tmp + tmp2;
    tmp2 = a->c[i].real * b->c[2].imag;
    tmp = a->c[i].imag * b->c[2].real;
    c->e[i][2].imag = tmp - tmp2;
}
}
