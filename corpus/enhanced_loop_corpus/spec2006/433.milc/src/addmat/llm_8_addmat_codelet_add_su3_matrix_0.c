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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++) {
        {
            double a_real = (a->e[i][j]).real;
            double a_imag = (a->e[i][j]).imag;
            double b_real = (b->e[i][j]).real;
            double b_imag = (b->e[i][j]).imag;
            (c->e[i][j]).real = a_real + b_real;
            (c->e[i][j]).imag = a_imag + b_imag;
        }
        ;
    }

}
