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
sum = 0.;
for (i = 0; i < 9; i++) {
    int row = i / 3;
    int col = i % 3;
    sum += a->e[row][col].real * b->e[row][col].real + a->e[row][col].imag * b->e[row][col].imag;
}
}
