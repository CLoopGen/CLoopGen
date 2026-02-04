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
    double temp_sum = 0.0;
    for (i = 0; i < 3; i++) {
        double row_accum = 0.0;
        for (j = 0; j < 3; j++) {
            // Introduce temporary accumulation to create intra-loop dependency (WAW on row_accum)
            // This adds a loop-carried dependency in the inner loop via row_accum
            row_accum += a->e[i][j].real * b->e[i][j].real + a->e[i][j].imag * b->e[i][j].imag;
        }
        temp_sum += row_accum; // Reduce row sums into total
    }
    sum = temp_sum; // Final assignment to output variable
}
