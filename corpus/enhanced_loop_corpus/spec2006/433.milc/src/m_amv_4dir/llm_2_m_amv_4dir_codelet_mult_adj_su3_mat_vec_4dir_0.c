#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

typedef struct {
    complex c[3];
} su3_vector;

extern int n;
extern double c0r;
extern double c0i;
extern double c1r;
extern double c1i;
extern double c2r;
extern double c2i;
extern double br;
extern double bi;
extern double a0;
extern double a1;
extern double a2;
extern su3_matrix *a;
extern su3_vector *b;
extern su3_vector *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < 4; n++ , a++ , c++) {
    double temp_real[3] = {0};
    double temp_imag[3] = {0};

    for (int i = 0; i < 3; i++) {
        br = b->c[i].real;
        bi = b->c[i].imag;

        for (int j = 0; j < 3; j++) {
            a0 = a->e[i][j].real;
            a1 = a->e[i][j].imag;

            temp_real[j] += a0 * br - a1 * bi;
            temp_imag[j] += a0 * bi + a1 * br;
        }
    }

    c->c[0].real = temp_real[0];
    c->c[0].imag = temp_imag[0];
    c->c[1].real = temp_real[1];
    c->c[1].imag = temp_imag[1];
    c->c[2].real = temp_real[2];
    c->c[2].imag = temp_imag[2];
}
}
