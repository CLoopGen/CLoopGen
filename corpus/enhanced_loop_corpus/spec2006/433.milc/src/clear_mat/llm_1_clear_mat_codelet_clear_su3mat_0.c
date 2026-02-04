#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_matrix *dest;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 3; i++) {
    int j = 0;
    dest->e[i][j].real = dest->e[i][j].imag = 0.;
    j = 1;
    dest->e[i][j].real = dest->e[i][j].imag = 0.;
    j = 2;
    dest->e[i][j].real = dest->e[i][j].imag = 0.;
}
}
