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
double c0r_local, c0i_local, c1r_local, c1i_local, c2r_local, c2i_local;
double br_local, bi_local;
const su3_matrix* a_ptr;
const su3_vector* b_ptr;
su3_vector* c_ptr;

for (n = 0; n < 4; n++) {
    a_ptr = a;
    b_ptr = b;
    c_ptr = c;

    br_local = b_ptr->c[0].real;
    bi_local = b_ptr->c[0].imag;

    c0r_local = a_ptr->e[0][0].real * br_local + a_ptr->e[0][0].imag * bi_local;
    c1r_local = a_ptr->e[0][1].real * br_local + a_ptr->e[0][1].imag * bi_local;
    c2r_local = a_ptr->e[0][2].real * br_local + a_ptr->e[0][2].imag * bi_local;

    c0i_local = a_ptr->e[0][0].real * bi_local - a_ptr->e[0][0].imag * br_local;
    c1i_local = a_ptr->e[0][1].real * bi_local - a_ptr->e[0][1].imag * br_local;
    c2i_local = a_ptr->e[0][2].real * bi_local - a_ptr->e[0][2].imag * br_local;

    br_local = b_ptr->c[1].real;
    bi_local = b_ptr->c[1].imag;

    c0r_local += a_ptr->e[1][0].real * br_local + a_ptr->e[1][0].imag * bi_local;
    c1r_local += a_ptr->e[1][1].real * br_local + a_ptr->e[1][1].imag * bi_local;
    c2r_local += a_ptr->e[1][2].real * br_local + a_ptr->e[1][2].imag * bi_local;

    c0i_local += a_ptr->e[1][0].real * bi_local - a_ptr->e[1][0].imag * br_local;
    c1i_local += a_ptr->e[1][1].real * bi_local - a_ptr->e[1][1].imag * br_local;
    c2i_local += a_ptr->e[1][2].real * bi_local - a_ptr->e[1][2].imag * br_local;

    br_local = b_ptr->c[2].real;
    bi_local = b_ptr->c[2].imag;

    c0r_local += a_ptr->e[2][0].real * br_local + a_ptr->e[2][0].imag * bi_local;
    c1r_local += a_ptr->e[2][1].real * br_local + a_ptr->e[2][1].imag * bi_local;
    c2r_local += a_ptr->e[2][2].real * br_local + a_ptr->e[2][2].imag * bi_local;

    c0i_local += a_ptr->e[2][0].real * bi_local - a_ptr->e[2][0].imag * br_local;
    c1i_local += a_ptr->e[2][1].real * bi_local - a_ptr->e[2][1].imag * br_local;
    c2i_local += a_ptr->e[2][2].real * bi_local - a_ptr->e[2][2].imag * br_local;

    c_ptr->c[0].real = c0r_local;
    c_ptr->c[0].imag = c0i_local;
    c_ptr->c[1].real = c1r_local;
    c_ptr->c[1].imag = c1i_local;
    c_ptr->c[2].real = c2r_local;
    c_ptr->c[2].imag = c2i_local;

    a++;
    c++;
}
}
