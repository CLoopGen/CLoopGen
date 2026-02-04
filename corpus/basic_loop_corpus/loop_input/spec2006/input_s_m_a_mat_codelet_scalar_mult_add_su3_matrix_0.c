#include <stdio.h>
#include <inttypes.h>
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

static su3_matrix a_data;
static su3_matrix b_data;
static su3_matrix c_data;

void init_vars() {
    a = &a_data;
    b = &b_data;
    c = &c_data;
    s = 1.5;

    for (int ii = 0; ii < 3; ii++) {
        for (int jj = 0; jj < 3; jj++) {
            a->e[ii][jj].real = sin(ii * 0.1) + cos(jj * 0.2);
            a->e[ii][jj].imag = cos(ii * 0.1) - sin(jj * 0.2);
            b->e[ii][jj].real = sin(jj * 0.3) + cos(ii * 0.4);
            b->e[ii][jj].imag = cos(jj * 0.3) - sin(ii * 0.4);
            c->e[ii][jj].real = 0.0;
            c->e[ii][jj].imag = 0.0;
        }
    }

    i = 0;
    j = 0;
}