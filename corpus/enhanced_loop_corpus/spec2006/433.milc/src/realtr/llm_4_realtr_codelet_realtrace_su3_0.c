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
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (sum = 0., i = 0; i < 3; i++)
    for (j = 0; j < 3; j++) {
        if (!(i == 1 && j == 1)) // Skip the center element
            sum += a->e[i][j].real * b->e[i][j].real + a->e[i][j].imag * b->e[i][j].imag;
    }
}
