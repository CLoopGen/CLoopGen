#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

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

static su3_matrix a_data[1024];
static su3_matrix b_data[1024];
static su3_matrix c_data[1024];

void init_vars() {
    a = a_data;
    b = b_data;
    c = c_data;

    for (int idx = 0; idx < 1024; idx++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a_data[idx].e[i][j].real = 1.0 + idx % 7;
                a_data[idx].e[i][j].imag = 0.5 + idx % 11;
                b_data[idx].e[i][j].real = 1.5 + idx % 13;
                b_data[idx].e[i][j].imag = 0.7 + idx % 17;
                c_data[idx].e[i][j].real = 0.0;
                c_data[idx].e[i][j].imag = 0.0;
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