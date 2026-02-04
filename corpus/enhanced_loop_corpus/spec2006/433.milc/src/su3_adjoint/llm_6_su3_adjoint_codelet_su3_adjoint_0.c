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
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            double temp_real = (a->e[j][i]).real;
            double temp_imag = (a->e[j][i]).imag;
            (b->e[i][j]).real = temp_real;
            (b->e[i][j]).imag = -temp_imag;
        }
}
