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

su3_matrix *a;
su3_vector *b;
su3_vector *c;
int i;
double t;
double ar;
double ai;
double br;
double bi;
double cr;
double ci;

static su3_matrix a_data[1 << 18]; // ~192KB of data
static su3_vector b_data[1 << 18];
static su3_vector c_data[1 << 18];

void init_vars() {
    a = a_data;
    b = b_data;
    c = c_data;

    for (int idx = 0; idx < (1 << 18); idx++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a_data[idx].e[i][j].real = (double)(idx + i * 3 + j) / 1.7;
                a_data[idx].e[i][j].imag = (double)(idx + i * 3 + j) / 2.3;
            }
        }
        for (int i = 0; i < 3; i++) {
            b_data[idx].c[i].real = (double)(idx * 3 + i) / 3.1;
            b_data[idx].c[i].imag = (double)(idx * 3 + i) / 4.1;
        }
    }

    for (int idx = 0; idx < (1 << 18); idx++) {
        for (int i = 0; i < 3; i++) {
            c_data[idx].c[i].real = 0.0;
            c_data[idx].c[i].imag = 0.0;
        }
    }

    i = 0;
    t = 0.0;
    ar = 0.0;
    ai = 0.0;
    br = 0.0;
    bi = 0.0;
    cr = 0.0;
    ci = 0.0;
}