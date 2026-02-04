#include <stdio.h>
#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

su3_matrix *a;
su3_matrix *b;
int i;
int j;

void init_vars() {
    // Allocate memory for a and b
    a = (su3_matrix*)__builtin_malloc(sizeof(su3_matrix));
    b = (su3_matrix*)__builtin_malloc(sizeof(su3_matrix));

    // Initialize all elements of a to non-zero values to ensure meaningful copy
    for (int ii = 0; ii < 3; ++ii) {
        for (int jj = 0; jj < 3; ++jj) {
            a->e[ii][jj].real = (double)(ii * 3 + jj + 1) * 1.1;
            a->e[ii][jj].imag = (double)(ii * 3 + jj + 1) * 2.2;
        }
    }

    // Ensure destination b is initialized to known state
    for (int ii = 0; ii < 3; ++ii) {
        for (int jj = 0; jj < 3; ++jj) {
            b->e[ii][jj].real = 0.0;
            b->e[ii][jj].imag = 0.0;
        }
    }

    // Initialize loop indices
    i = 0;
    j = 0;
}