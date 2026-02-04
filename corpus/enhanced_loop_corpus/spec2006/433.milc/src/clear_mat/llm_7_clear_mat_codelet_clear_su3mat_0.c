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
    // Variant 2: Eliminate potential parallelism by introducing artificial WAR dependencies
    // Reorder stores in reverse order and use temporary structure to break direct independence
    // Also unroll inner loop manually to expose fine-grained dependencies
    su3_matrix temp;
    // Initialize temp to zero
    for (int ii = 0; ii < 3; ii++)
        for (int jj = 0; jj < 3; jj++)
            temp.e[ii][jj].real = temp.e[ii][jj].imag = 0.;

    // Forward copy to temp introduces RAW dependence per element
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            temp.e[i][j].real = dest->e[i][j].real;  // RAW: read before write in next step
            temp.e[i][j].imag = dest->e[i][j].imag;
        }
    }

    // Reverse-order write back with WAR: writing to dest creates Write-After-Read hazard relative to above
    // Loop-carried dependence introduced via index reversal
    for (i = 2; i >= 0; i--) {
        for (j = 2; j >= 0; j--) {
            dest->e[i][j].real = temp.e[i][j].real;
            dest->e[i][j].imag = temp.e[i][j].imag;
        }
    }

    // Final zeroing phase — now independent and parallelizable
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            dest->e[i][j].real = 0.;
            dest->e[i][j].imag = 0.;
        }
}
