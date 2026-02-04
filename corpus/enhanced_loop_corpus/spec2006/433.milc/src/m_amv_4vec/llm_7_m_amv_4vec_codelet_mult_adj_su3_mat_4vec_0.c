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

extern int n;
extern double c0r;
extern double c0i;
extern double c1r;
extern double c1i;
extern double c2r;
extern double c2i;
extern double br;
extern double bi;
extern double a0;
extern double a1;
extern double a2;
extern su3_matrix *a;
extern su3_vector *b;
extern su3_vector *c;
extern su3_vector *cc[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double c0r_local, c1r_local, c2r_local;
double c0i_local, c1i_local, c2i_local;

for (n = 0; n < 4; n++) {
    c = cc[n];
    su3_matrix *a_current = &a[n];

    br = b->c[0].real;
    bi = b->c[0].imag;

    a0 = a_current->e[0][0].real;
    a1 = a_current->e[0][1].real;
    a2 = a_current->e[0][2].real;

    c0r_local = a0 * br;
    c1r_local = a1 * br;
    c2r_local = a2 * br;

    c0i_local = a0 * bi;
    c1i_local = a1 * bi;
    c2i_local = a2 * bi;

    a0 = a_current->e[0][0].imag;
    a1 = a_current->e[0][1].imag;
    a2 = a_current->e[0][2].imag;

    c0r_local += a0 * bi;
    c1r_local += a1 * bi;
    c2r_local += a2 * bi;

    c0i_local -= a0 * br;
    c1i_local -= a1 * br;
    c2i_local -= a2 * br;

    br = b->c[1].real;
    bi = b->c[1].imag;

    a0 = a_current->e[1][0].real;
    a1 = a_current->e[1][1].real;
    a2 = a_current->e[1][2].real;

    c0r_local += a0 * br;
    c1r_local += a1 * br;
    c2r_local += a2 * br;

    c0i_local += a0 * bi;
    c1i_local += a1 * bi;
    c2i_local += a2 * bi;

    a0 = a_current->e[1][0].imag;
    a1 = a_current->e[1][1].imag;
    a2 = a_current->e[1][2].imag;

    c0r_local += a0 * bi;
    c1r_local += a1 * bi;
    c2r_local += a2 * bi;

    c0i_local -= a0 * br;
    c1i_local -= a1 * br;
    c2i_local -= a2 * br;

    br = b->c[2].real;
    bi = b->c[2].imag;

    a0 = a_current->e[2][0].real;
    a1 = a_current->e[2][1].real;
    a2 = a_current->e[2][2].real;

    c0r_local += a0 * br;
    c1r_local += a1 * br;
    c2r_local += a2 * br;

    c0i_local += a0 * bi;
    c1i_local += a1 * bi;
    c2i_local += a2 * bi;

    a0 = a_current->e[2][0].imag;
    a1 = a_current->e[2][1].imag;
    a2 = a_current->e[2][2].imag;

    c0r_local += a0 * bi;
    c1r_local += a1 * bi;
    c2r_local += a2 * bi;

    c0i_local -= a0 * br;
    c1i_local -= a1 * br;
    c2i_local -= a2 * br;

    c->c[0].real = c0r_local;
    c->c[0].imag = c0i_local;
    c->c[1].real = c1r_local;
    c->c[1].imag = c1i_local;
    c->c[2].real = c2r_local;
    c->c[2].imag = c2i_local;
}
}
