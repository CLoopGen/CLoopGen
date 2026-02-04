#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_matrix *a;
extern su3_matrix *b;
extern su3_matrix *c;
extern int j;
extern double a0r;
extern double a0i;
extern double a1r;
extern double a1i;
extern double a2r;
extern double a2i;
extern double b0r;
extern double b0i;
extern double b1r;
extern double b1i;
extern double b2r;
extern double b2i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < 3; j++) {
    a0r = a->e[0][0].real;
    a0i = a->e[0][0].imag;
    b0r = b->e[0][j].real;
    b0i = b->e[0][j].imag;
    a1r = a->e[1][0].real;
    a1i = a->e[1][0].imag;
    b1r = b->e[1][j].real;
    b1i = b->e[1][j].imag;
    a2r = a->e[2][0].real;
    a2i = a->e[2][0].imag;
    b2r = b->e[2][j].real;
    b2i = b->e[2][j].imag;
    c->e[0][j].real = a0r * b0r + a0i * b0i + a1r * b1r + a1i * b1i + a2r * b2r + a2i * b2i;
    c->e[0][j].imag = a0r * b0i - a0i * b0r + a1r * b1i - a1i * b1r + a2r * b2i - a2i * b2r;
    a0r = a->e[0][1].real;
    a0i = a->e[0][1].imag;
    b0r = b->e[0][j].real;
    b0i = b->e[0][j].imag;
    a1r = a->e[1][1].real;
    a1i = a->e[1][1].imag;
    b1r = b->e[1][j].real;
    b1i = b->e[1][j].imag;
    a2r = a->e[2][1].real;
    a2i = a->e[2][1].imag;
    b2r = b->e[2][j].real;
    b2i = b->e[2][j].imag;
    c->e[1][j].real = a0r * b0r + a0i * b0i + a1r * b1r + a1i * b1i + a2r * b2r + a2i * b2i;
    c->e[1][j].imag = a0r * b0i - a0i * b0r + a1r * b1i - a1i * b1r + a2r * b2i - a2i * b2r;
    a0r = a->e[0][2].real;
    a0i = a->e[0][2].imag;
    b0r = b->e[0][j].real;
    b0i = b->e[0][j].imag;
    a1r = a->e[1][2].real;
    a1i = a->e[1][2].imag;
    b1r = b->e[1][j].real;
    b1i = b->e[1][j].imag;
    a2r = a->e[2][2].real;
    a2i = a->e[2][2].imag;
    b2r = b->e[2][j].real;
    b2i = b->e[2][j].imag;
    c->e[2][j].real = a0r * b0r + a0i * b0i + a1r * b1r + a1i * b1i + a2r * b2r + a2i * b2i;
    c->e[2][j].imag = a0r * b0i - a0i * b0r + a1r * b1i - a1i * b1r + a2r * b2i - a2i * b2r;
}

}
