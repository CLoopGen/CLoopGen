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
extern int i;
extern int j;
extern double t;
extern double ar;
extern double ai;
extern double br;
extern double bi;
extern double cr;
extern double ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 3; j++)
    for (i = 0; i < 3; i++) {
        double sum_real = 0.0;
        double sum_imag = 0.0;
        const su3_matrix *a_local = a;
        const su3_matrix *b_local = b;
        su3_matrix *c_local = c;
        for (int k = 0; k < 3; k++) {
            double ar_k = a_local->e[i][k].real;
            double ai_k = a_local->e[i][k].imag;
            double br_k = b_local->e[k][j].real;
            double bi_k = b_local->e[k][j].imag;
            sum_real += ar_k * br_k - ai_k * bi_k;
            sum_imag += ar_k * bi_k + ai_k * br_k;
        }
        c_local->e[i][j].real = sum_real;
        c_local->e[i][j].imag = sum_imag;
    }
}
