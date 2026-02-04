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
for (i = 0; i < 9; i++) {
    int row = i / 3;
    int col = i % 3;
    c->e[row][col].real = a->e[row][col].real - s * b->e[row][col].real;
    c->e[row][col].imag = a->e[row][col].imag - s * b->e[row][col].imag;
}
}
