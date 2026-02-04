#include <stdio.h>
#include <inttypes.h>

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

su3_matrix a_data[100000];
su3_vector b_data[100000];
su3_vector c_data[100000];

void init_vars() {
    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                a_data[i].e[j][k].real = 1.0 / (1 + i + j + k);
                a_data[i].e[j][k].imag = 0.5 / (1 + i + j + k);
            }
        }
        for (int j = 0; j < 3; j++) {
            b_data[i].c[j].real = 1.0 + j;
            b_data[i].c[j].imag = 0.5 + j;
            c_data[i].c[j].real = 0.0;
            c_data[i].c[j].imag = 0.0;
        }
    }
    a = a_data;
    b = b_data;
    c = c_data;
}