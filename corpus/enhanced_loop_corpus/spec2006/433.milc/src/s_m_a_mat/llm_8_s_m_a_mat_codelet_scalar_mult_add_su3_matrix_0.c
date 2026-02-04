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
        double s_real, s_imag;
        for (j = 0; j < 3; j++) {
            s_real = s * b->e[i][j].real;
            s_imag = s * b->e[i][j].imag;
            c->e[i][j].real = a->e[i][j].real + s_real;
            c->e[i][j].imag = a->e[i][j].imag + s_imag;
        }
    }
}
