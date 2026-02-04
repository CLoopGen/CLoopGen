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
    static su3_matrix data_a;
    static su3_matrix data_b;
    a = &data_a;
    b = &data_b;
}