#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_vector *a;
extern su3_vector *b;
extern su3_matrix *c;
extern int i;
extern int j;
extern double tmp;
extern double tmp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using indirect access via index arrays to simulate irregular memory strides
    int idx[3] = {0, 1, 2}; // Indirect indices (could be modified for different patterns)
    for (int ii = 0; ii < 3; ii++)
        for (int jj = 0; jj < 3; jj++) {
            int i = idx[ii]; // Indirect access for i
            int j = idx[jj]; // Indirect access for j
            tmp2 = a->c[i].real * b->c[j].real;
            tmp = a->c[i].imag * b->c[j].imag;
            c->e[i][j].real = tmp + tmp2;
            tmp2 = a->c[i].real * b->c[j].imag;
            tmp = a->c[i].imag * b->c[j].real;
            c->e[i][j].imag = tmp - tmp2;
        }
}
