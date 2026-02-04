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
double sum;

static su3_matrix a_data;
static su3_matrix b_data;

void init_vars() {
    a = &a_data;
    b = &b_data;
    i = 0;
    j = 0;
    sum = 0.0;

    for (int ii = 0; ii < 3; ++ii) {
        for (int jj = 0; jj < 3; ++jj) {
            a->e[ii][jj].real = 1.0 + ii * 3 + jj;
            a->e[ii][jj].imag = -0.5 + ii * 3 + jj;
            b->e[ii][jj].real = 2.0 - ii * 0.1 - jj * 0.2;
            b->e[ii][jj].imag = 0.3 * (ii * 3 + jj);
        }
    }
}