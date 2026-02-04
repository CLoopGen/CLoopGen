#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

typedef struct {
    complex c[3];
} su3_vector;

int n;
double c0r;
double c0i;
double c1r;
double c1i;
double c2r;
double c2i;
double br;
double bi;
double a0;
double a1;
double a2;
su3_matrix *a;
su3_vector *b;
su3_vector *c;
su3_vector *cc[4];

static su3_matrix a_data[4];
static su3_vector b_data;
static su3_vector c_data[4];

void init_vars() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                a_data[i].e[j][k].real = sin((i*9 + j*3 + k + 1) * 0.1);
                a_data[i].e[j][k].imag = cos((i*9 + j*3 + k + 1) * 0.1);
            }
        }
        cc[i] = &c_data[i];
        for (int j = 0; j < 3; j++) {
            c_data[i].c[j].real = 0.0;
            c_data[i].c[j].imag = 0.0;
        }
    }

    for (int j = 0; j < 3; j++) {
        b_data.c[j].real = sin((j + 1) * 0.5);
        b_data.c[j].imag = cos((j + 1) * 0.5);
    }

    a = a_data;
    b = &b_data;
    c = NULL;
    n = 0;
}