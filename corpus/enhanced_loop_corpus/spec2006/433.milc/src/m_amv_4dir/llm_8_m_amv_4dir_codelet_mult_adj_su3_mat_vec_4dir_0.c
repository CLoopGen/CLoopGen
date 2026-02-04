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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < 8; n += 2, a += 2, c += 2) {
    // Unrolled version: two iterations of original loop combined
    double br1, bi1, br2, bi2;
    double a0r, a1r, a2r, a0i, a1i, a2i;
    double c0r1 = 0.0, c1r1 = 0.0, c2r1 = 0.0;
    double c0i1 = 0.0, c1i1 = 0.0, c2i1 = 0.0;
    double c0r2 = 0.0, c1r2 = 0.0, c2r2 = 0.0;
    double c0i2 = 0.0, c1i2 = 0.0, c2i2 = 0.0;

    // First iteration (original n)
    br1 = b->c[0].real;
    bi1 = b->c[0].imag;
    a0r = a->e[0][0].real; a1r = a->e[0][1].real; a2r = a->e[0][2].real;
    c0r1 = a0r * br1; c1r1 = a1r * br1; c2r1 = a2r * br1;
    c0i1 = a0r * bi1; c1i1 = a1r * bi1; c2i1 = a2r * bi1;
    a0i = a->e[0][0].imag; a1i = a->e[0][1].imag; a2i = a->e[0][2].imag;
    c0r1 += a0i * bi1; c1r1 += a1i * bi1; c2r1 += a2i * bi1;
    c0i1 -= a0i * br1; c1i1 -= a1i * br1; c2i1 -= a2i * br1;

    br1 = b->c[1].real; bi1 = b->c[1].imag;
    a0r = a->e[1][0].real; a1r = a->e[1][1].real; a2r = a->e[1][2].real;
    c0r1 += a0r * br1; c1r1 += a1r * br1; c2r1 += a2r * br1;
    c0i1 += a0r * bi1; c1i1 += a1r * bi1; c2i1 += a2r * bi1;
    a0i = a->e[1][0].imag; a1i = a->e[1][1].imag; a2i = a->e[1][2].imag;
    c0r1 += a0i * bi1; c1r1 += a1i * bi1; c2r1 += a2i * bi1;
    c0i1 -= a0i * br1; c1i1 -= a1i * br1; c2i1 -= a2i * br1;

    br1 = b->c[2].real; bi1 = b->c[2].imag;
    a0r = a->e[2][0].real; a1r = a->e[2][1].real; a2r = a->e[2][2].real;
    c0r1 += a0r * br1; c1r1 += a1r * br1; c2r1 += a2r * br1;
    c0i1 += a0r * bi1; c1i1 += a1r * bi1; c2i1 += a2r * bi1;
    a0i = a->e[2][0].imag; a1i = a->e[2][1].imag; a2i = a->e[2][2].imag;
    c0r1 += a0i * bi1; c1r1 += a1i * bi1; c2r1 += a2i * bi1;
    c0i1 -= a0i * br1; c1i1 -= a1i * br1; c2i1 -= a2i * br1;

    c->c[0].real = c0r1; c->c[0].imag = c0i1;
    c->c[1].real = c1r1; c->c[1].imag = c1i1;
    c->c[2].real = c2r1; c->c[2].imag = c2i1;

    // Second iteration (n+1), if within bounds
    if (n + 1 < 8) {
        su3_matrix* a_next = a + 1;
        su3_vector* c_next = c + 1;

        br2 = b->c[0].real;
        bi2 = b->c[0].imag;
        a0r = a_next->e[0][0].real; a1r = a_next->e[0][1].real; a2r = a_next->e[0][2].real;
        c0r2 = a0r * br2; c1r2 = a1r * br2; c2r2 = a2r * br2;
        c0i2 = a0r * bi2; c1i2 = a1r * bi2; c2i2 = a2r * bi2;
        a0i = a_next->e[0][0].imag; a1i = a_next->e[0][1].imag; a2i = a_next->e[0][2].imag;
        c0r2 += a0i * bi2; c1r2 += a1i * bi2; c2r2 += a2i * bi2;
        c0i2 -= a0i * br2; c1i2 -= a1i * br2; c2i2 -= a2i * br2;

        br2 = b->c[1].real; bi2 = b->c[1].imag;
        a0r = a_next->e[1][0].real; a1r = a_next->e[1][1].real; a2r = a_next->e[1][2].real;
        c0r2 += a0r * br2; c1r2 += a1r * br2; c2r2 += a2r * br2;
        c0i2 += a0r * bi2; c1i2 += a1r * bi2; c2i2 += a2r * bi2;
        a0i = a_next->e[1][0].imag; a1i = a_next->e[1][1].imag; a2i = a_next->e[1][2].imag;
        c0r2 += a0i * bi2; c1r2 += a1i * bi2; c2r2 += a2i * bi2;
        c0i2 -= a0i * br2; c1i2 -= a1i * br2; c2i2 -= a2i * br2;

        br2 = b->c[2].real; bi2 = b->c[2].imag;
        a0r = a_next->e[2][0].real; a1r = a_next->e[2][1].real; a2r = a_next->e[2][2].real;
        c0r2 += a0r * br2; c1r2 += a1r * br2; c2r2 += a2r * br2;
        c0i2 += a0r * bi2; c1i2 += a1r * bi2; c2i2 += a2r * bi2;
        a0i = a_next->e[2][0].imag; a1i = a_next->e[2][1].imag; a2i = a_next->e[2][2].imag;
        c0r2 += a0i * bi2; c1r2 += a1i * bi2; c2r2 += a2i * bi2;
        c0i2 -= a0i * br2; c1i2 -= a1i * br2; c2i2 -= a2i * br2;

        c_next->c[0].real = c0r2; c_next->c[0].imag = c0i2;
        c_next->c[1].real = c1r2; c_next->c[1].imag = c1i2;
        c_next->c[2].real = c2r2; c_next->c[2].imag = c2i2;
    }
}
}
