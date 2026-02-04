#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

su3_matrix *a;
su3_matrix *b;
double s;
su3_matrix *c;
int i;
int j;

void init_vars() {
    // Allocate memory for a, b, and c
    a = (su3_matrix*)malloc(sizeof(su3_matrix));
    b = (su3_matrix*)malloc(sizeof(su3_matrix));
    c = (su3_matrix*)malloc(sizeof(su3_matrix));
    
    // Initialize scalar multiplier
    s = 1.5;
    
    // Initialize matrix a and b with non-trivial values
    for (int ii = 0; ii < 3; ii++) {
        for (int jj = 0; jj < 3; jj++) {
            a->e[ii][jj].real = (ii + 1) * (jj + 1) * 0.1;
            a->e[ii][jj].imag = (ii + 1) * (jj + 1) * 0.2;
            b->e[ii][jj].real = (ii + 1) * (jj + 1) * 0.3;
            b->e[ii][jj].imag = (ii + 1) * (jj + 1) * 0.4;
        }
    }
    
    // Initialize loop indices
    i = 0;
    j = 0;
}