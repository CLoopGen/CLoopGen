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
su3_vector *b0;
su3_vector *b1;
su3_vector *b2;
su3_vector *b3;
su3_vector *c;
int i;
int n;
su3_matrix *at;
su3_vector *b;
double t;
double ar;
double ai;
double br;
double bi;
double cr;
double ci;

static su3_matrix a_data[4];
static su3_vector b0_data;
static su3_vector b1_data;
static su3_vector b2_data;
static su3_vector b3_data;
static su3_vector c_data;

void init_vars() {
    a = a_data;
    b0 = &b0_data;
    b1 = &b1_data;
    b2 = &b2_data;
    b3 = &b3_data;
    c = &c_data;
    at = 0;
    b = 0;
    i = 0;
    n = 0;
    t = 0.0;
    ar = 0.0;
    ai = 0.0;
    br = 0.0;
    bi = 0.0;
    cr = 0.0;
    ci = 0.0;

    for (int mat = 0; mat < 4; mat++) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                a_data[mat].e[row][col].real = (mat + 1) * (row + 1) * (col + 1) * 0.1;
                a_data[mat].e[row][col].imag = (mat + 1) * (row + 1) * (col + 1) * 0.2;
            }
        }
    }

    for (int j = 0; j < 3; j++) {
        b0_data.c[j].real = j * 1.5;
        b0_data.c[j].imag = j * 2.5;
        b1_data.c[j].real = j * 1.6;
        b1_data.c[j].imag = j * 2.6;
        b2_data.c[j].real = j * 1.7;
        b2_data.c[j].imag = j * 2.7;
        b3_data.c[j].real = j * 1.8;
        b3_data.c[j].imag = j * 2.8;
        c->c[j].real = 0.0;
        c->c[j].imag = 0.0;
    }
}