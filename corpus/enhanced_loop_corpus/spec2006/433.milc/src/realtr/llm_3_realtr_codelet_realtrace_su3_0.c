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
    // Variant 2: Consecutive Flat Array Access via Type Punning (Memory Layout Exploitation)
    // Treat the 3x3 complex matrix as a linear array of doubles (each complex has 2 doubles)
    // Total of 3*3*2*2 = 36 doubles (real and imag from both a and b), but we pair them by field
    double *pa = (double*)a;
    double *pb = (double*)b;
    sum = 0.0;
    for (i = 0; i < 18; i += 2) {  // Step by 2 to process one complex number at a time
        sum += pa[i] * pb[i] + pa[i+1] * pb[i+1];  // real*real + imag*imag
    }
}
