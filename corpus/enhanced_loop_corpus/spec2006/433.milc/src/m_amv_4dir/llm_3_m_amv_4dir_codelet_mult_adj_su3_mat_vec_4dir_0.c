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
su3_vector *c_base = c;
su3_matrix *a_base = a;
su3_vector b_cache;

for (n = 0; n < 4; n++) {
    b_cache = *b;

    c0r = c1r = c2r = 0.0;
    c0i = c1i = c2i = 0.0;

    const su3_matrix *A = &a_base[n];

    for (int col = 0; col < 3; col++) {
        br = b_cache.c[col].real;
        bi = b_cache.c[col].imag;

        for (int row = 0; row < 3; row++) {
            double real_part = A->e[row][col].real;
            double imag_part = A->e[row][col].imag;

            switch (row) {
                case 0:
                    c0r += real_part * br - imag_part * bi;
                    c0i += real_part * bi + imag_part * br;
                    break;
                case 1:
                    c1r += real_part * br - imag_part * bi;
                    c1i += real_part * bi + imag_part * br;
                    break;
                case 2:
                    c2r += real_part * br - imag_part * bi;
                    c2i += real_part * bi + imag_part * br;
                    break;
            }
        }
    }

    su3_vector *target = &c_base[n];
    target->c[0].real = c0r;
    target->c[0].imag = c0i;
    target->c[1].real = c1r;
    target->c[1].imag = c1i;
    target->c[2].real = c2r;
    target->c[2].imag = c2i;
}
}
