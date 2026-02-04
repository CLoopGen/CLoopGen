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
    // Variant 2: Eliminate all potential loop-carried dependencies by unrolling
    // and parallelizing independent operations. No data reuse across iterations.
    int idx[9][2] = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
    for (int k = 0; k < 9; k++) {
        int i = idx[k][0];
        int j = idx[k][1];
        double real_val = a->e[i][j].real - s * b->e[i][j].real;
        double imag_val = a->e[i][j].imag - s * b->e[i][j].imag;
        // Write output only once, no interference between iterations
        c->e[i][j].real = real_val;
        c->e[i][j].imag = imag_val;
    }
}
