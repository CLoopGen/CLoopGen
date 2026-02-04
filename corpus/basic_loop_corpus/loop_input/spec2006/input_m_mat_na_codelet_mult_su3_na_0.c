#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>
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
su3_matrix *c;
int i;
int j;
double t;
double ar;
double ai;
double br;
double bi;
double cr;
double ci;

void init_vars() {
    const int num_matrices = 100000;
    a = (su3_matrix*)malloc(num_matrices * sizeof(su3_matrix));
    b = (su3_matrix*)malloc(num_matrices * sizeof(su3_matrix));
    c = (su3_matrix*)malloc(num_matrices * sizeof(su3_matrix));

    srand(time(NULL));
    for (int idx = 0; idx < num_matrices; idx++) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                a[idx].e[row][col].real = (double)rand() / RAND_MAX;
                a[idx].e[row][col].imag = (double)rand() / RAND_MAX;
                b[idx].e[row][col].real = (double)rand() / RAND_MAX;
                b[idx].e[row][col].imag = (double)rand() / RAND_MAX;
                c[idx].e[row][col].real = 0.0;
                c[idx].e[row][col].imag = 0.0;
            }
        }
    }

    i = 0;
    j = 0;
    t = 0.0;
    ar = 0.0;
    ai = 0.0;
    br = 0.0;
    bi = 0.0;
    cr = 0.0;
    ci = 0.0;
}