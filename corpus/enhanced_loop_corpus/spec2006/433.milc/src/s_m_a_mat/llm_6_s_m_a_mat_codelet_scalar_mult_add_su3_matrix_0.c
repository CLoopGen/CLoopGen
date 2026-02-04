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
    double temp_real[3][3];
    double temp_imag[3][3];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            temp_real[i][j] = s * b->e[i][j].real;
            temp_imag[i][j] = s * b->e[i][j].imag;
        }
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            c->e[i][j].real = a->e[i][j].real + temp_real[i][j];
            c->e[i][j].imag = a->e[i][j].imag + temp_imag[i][j];
        }
}
