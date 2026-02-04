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
for (n = 0; n < 2; n++ , a++ , c++) {
    for (int m = 0; m < 2; m++) {
        br = b->c[m].real;
        bi = b->c[m].imag;
        for (int j = 0; j < 3; j++) {
            a0 = a->e[m][0].real;
            a1 = a->e[m][1].real;
            a2 = a->e[m][2].real;
            double temp0r = a0 * br;
            double temp1r = a1 * br;
            double temp2r = a2 * br;
            double temp0i = a0 * bi;
            double temp1i = a1 * bi;
            double temp2i = a2 * bi;
            a0 = a->e[m][0].imag;
            a1 = a->e[m][1].imag;
            a2 = a->e[m][2].imag;
            temp0r += a0 * bi;
            temp1r += a1 * bi;
            temp2r += a2 * bi;
            temp0i -= a0 * br;
            temp1i -= a1 * br;
            temp2i -= a2 * br;

            if (m == 0 && j == 0) {
                c0r = temp0r; c1r = temp1r; c2r = temp2r;
                c0i = temp0i; c1i = temp1i; c2i = temp2i;
            } else {
                c0r += temp0r; c1r += temp1r; c2r += temp2r;
                c0i += temp0i; c1i += temp1i; c2i += temp2i;
            }
        }
        if (m == 1) {
            c->c[0].real = c0r;
            c->c[0].imag = c0i;
            c->c[1].real = c1r;
            c->c[1].imag = c1i;
            c->c[2].real = c2r;
            c->c[2].imag = c2i;
            c++;
            a++;
            n++;
        }
    }
}
}
