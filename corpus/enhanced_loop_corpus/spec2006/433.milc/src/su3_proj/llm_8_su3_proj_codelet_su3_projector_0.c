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
    double a_real = a->c[i].real;
    double a_imag = a->c[i].imag;
    for (j = 0; j < 3; j++) {
        double b_real = b->c[j].real;
        double b_imag = b->c[j].imag;
        c->e[i][j].real = a_real * b_real + a_imag * b_imag;
        c->e[i][j].imag = a_imag * b_real - a_real * b_imag;
    }
}
}
