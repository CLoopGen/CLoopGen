#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

su3_matrix *dest;
int i;
int j;

void init_vars() {
    dest = (su3_matrix*)calloc(1, sizeof(su3_matrix));
}

void loop();