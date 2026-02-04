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
for (n = 0; n < 4; n++) {
    su3_matrix *a_ptr = &a[n];  // Use base pointer with indexing for consecutive memory access
    c = cc[n];
    double br0 = b->c[0].real, bi0 = b->c[0].imag;
    double br1 = b->c[1].real, bi1 = b->c[1].imag;
    double br2 = b->c[2].real, bi2 = b->c[2].imag;

    // Initialize accumulators
    double c0r = 0.0, c1r = 0.0, c2r = 0.0;
    double c0i = 0.0, c1i = 0.0, c2i = 0.0;

    // Process row 0
    const complex *row0 = a_ptr->e[0];
    c0r += row0[0].real * br0 + row0[0].imag * bi0;
    c0i += row0[0].real * bi0 - row0[0].imag * br0;
    c1r += row0[1].real * br0 + row0[1].imag * bi0;
    c1i += row0[1].real * bi0 - row0[1].imag * br0;
    c2r += row0[2].real * br0 + row0[2].imag * bi0;
    c2i += row0[2].real * bi0 - row0[2].imag * br0;

    // Process row 1
    const complex *row1 = a_ptr->e[1];
    c0r += row1[0].real * br1 + row1[0].imag * bi1;
    c0i += row1[0].real * bi1 - row1[0].imag * br1;
    c1r += row1[1].real * br1 + row1[1].imag * bi1;
    c1i += row1[1].real * bi1 - row1[1].imag * br1;
    c2r += row1[2].real * br1 + row1[2].imag * bi1;
    c2i += row1[2].real * bi1 - row1[2].imag * br1;

    // Process row 2
    const complex *row2 = a_ptr->e[2];
    c0r += row2[0].real * br2 + row2[0].imag * bi2;
    c0i += row2[0].real * bi2 - row2[0].imag * br2;
    c1r += row2[1].real * br2 + row2[1].imag * bi2;
    c1i += row2[1].real * bi2 - row2[1].imag * br2;
    c2r += row2[2].real * br2 + row2[2].imag * bi2;
    c2i += row2[2].real * bi2 - row2[2].imag * br2;

    // Store results
    c->c[0].real = c0r; c->c[0].imag = c0i;
    c->c[1].real = c1r; c->c[1].imag = c1i;
    c->c[2].real = c2r; c->c[2].imag = c2i;
}
}
