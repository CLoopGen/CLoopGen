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
extern int i;
extern int j;
extern double t;
extern double ar;
extern double ai;
extern double br;
extern double bi;
extern double cr;
extern double ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_real[3][3] = {0};
    double temp_imag[3][3] = {0};
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            // Introduce temporary accumulation to create WAR and WAW dependencies on temp arrays
            // Eliminate immediate reuse of cr/ci by accumulating into temporaries per (i,j)
            ar = a->e[i][0].real;
            ai = a->e[i][0].imag;
            br = b->e[0][j].real;  // Transposed access to introduce different dependency pattern
            bi = b->e[0][j].imag;
            t = ar * br - ai * bi;
            temp_real[i][j] += t;
            t = ar * bi + ai * br;
            temp_imag[i][j] += t;

            ar = a->e[i][1].real;
            ai = a->e[i][1].imag;
            br = b->e[1][j].real;
            bi = b->e[1][j].imag;
            t = ar * br - ai * bi;
            temp_real[i][j] += t;
            t = ar * bi + ai * br;
            temp_imag[i][j] += t;

            ar = a->e[i][2].real;
            ai = a->e[i][2].imag;
            br = b->e[2][j].real;
            bi = b->e[2][j].imag;
            t = ar * br - ai * bi;
            temp_real[i][j] += t;
            t = ar * bi + ai * br;
            temp_imag[i][j] += t;

            c->e[i][j].real = temp_real[i][j];
            c->e[i][j].imag = temp_imag[i][j];
        }
}
