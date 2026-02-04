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
extern int i;
extern int j;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
sum = 0.;
for (i = 0; i < 3; i++) {
    sum += a->e[i][0].real * b->e[i][0].real + a->e[i][0].imag * b->e[i][0].imag;
    sum += a->e[i][1].real * b->e[i][1].real + a->e[i][1].imag * b->e[i][1].imag;
    sum += a->e[i][2].real * b->e[i][2].real + a->e[i][2].imag * b->e[i][2].imag;
}
}
