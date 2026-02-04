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
extern su3_matrix *c;
extern int j;
extern double a0r;
extern double a0i;
extern double a1r;
extern double a1i;
extern double a2r;
extern double a2i;
extern double b0r;
extern double b0i;
extern double b1r;
extern double b1i;
extern double b2r;
extern double b2i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 1; j++) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            double sum_real = 0.0, sum_imag = 0.0;
            for (int k = 0; k < 3; k++) {
                double a_real = a->e[row][k].real;
                double a_imag = a->e[row][k].imag;
                double b_real = b->e[k][col].real;
                double b_imag = b->e[k][col].imag;
                sum_real += a_real * b_real - a_imag * b_imag;
                sum_imag += a_real * b_imag + a_imag * b_real;
            }
            c->e[row][col].real = sum_real;
            c->e[row][col].imag = sum_imag;
        }
    }
}
}
