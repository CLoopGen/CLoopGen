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
su3_matrix *c;
int j;
double a0r;
double a0i;
double a1r;
double a1i;
double a2r;
double a2i;
double b0r;
double b0i;
double b1r;
double b1i;
double b2r;
double b2i;

static su3_matrix a_data;
static su3_matrix b_data;
static su3_matrix c_data;

void init_vars() {
    a = &a_data;
    b = &b_data;
    c = &c_data;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a->e[i][j].real = (double)(i * 3 + j + 1) * 0.1;
            a->e[i][j].imag = (double)(i * 3 + j + 1) * 0.2;
            b->e[i][j].real = (double)(i * 3 + j + 1) * 0.3;
            b->e[i][j].imag = (double)(i * 3 + j + 1) * 0.4;
            c->e[i][j].real = 0.0;
            c->e[i][j].imag = 0.0;
        }
    }
    
    j = 0;
    a0r = 0.0;
    a0i = 0.0;
    a1r = 0.0;
    a1i = 0.0;
    a2r = 0.0;
    a2i = 0.0;
    b0r = 0.0;
    b0i = 0.0;
    b1r = 0.0;
    b1i = 0.0;
    b2r = 0.0;
    b2i = 0.0;
}