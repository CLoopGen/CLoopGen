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
    double temp_real[3][3];
    double temp_imag[3][3];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            tmp2 = a->c[i].real * b->c[j].real;
            tmp = a->c[i].imag * b->c[j].imag;
            temp_real[i][j] = tmp + tmp2;
            tmp2 = a->c[i].real * b->c[j].imag;
            tmp = a->c[i].imag * b->c[j].real;
            temp_imag[i][j] = tmp - tmp2;
        }
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            c->e[i][j].real = temp_real[i][j];
            c->e[i][j].imag = temp_imag[i][j];
        }
}
