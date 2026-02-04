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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i++) {
    {
        (b->e[i][0]).real = (a->e[0][i]).real;
        (b->e[i][0]).imag = -(a->e[0][i]).imag;
    }
    {
        (b->e[i][1]).real = (a->e[1][i]).real;
        (b->e[i][1]).imag = -(a->e[1][i]).imag;
    }
    {
        (b->e[i][2]).real = (a->e[2][i]).real;
        (b->e[i][2]).imag = -(a->e[2][i]).imag;
    }
}
}
