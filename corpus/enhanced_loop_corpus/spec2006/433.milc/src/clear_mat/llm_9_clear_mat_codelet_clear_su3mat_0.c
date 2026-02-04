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
int i, j;
for (i = 0; i < 3; i++) {
    dest->e[i][i].real = 1.0;
    dest->e[i][i].imag = 0.0;
    if (i > 0) {
        dest->e[i][i-1].real = -0.5;
        dest->e[i-1][i].imag = 0.5;
    }
}
}
