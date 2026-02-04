#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    complex *base;
    complex **me;
} ZMAT;

extern ZMAT *mat;
extern ZMAT *out;
extern int i;
extern int k;
extern double c;
extern complex s;
extern u_int j;
extern complex x;
extern complex y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic to improve spatial locality
    complex *col_i = &(out->me[0][i]);
    complex *col_k = &(out->me[0][k]);
    u_int m = mat->m;
    for (j = 0; j < m; j++) {
        x = col_i[j];
        y = col_k[j];
        col_i[j].re = c * x.re - s.re * y.re - s.im * y.im;
        col_i[j].im = c * x.im - s.re * y.im + s.im * y.re;
        col_k[j].re = c * y.re + s.re * x.re - s.im * x.im;
        col_k[j].im = c * y.im + s.re * x.im + s.im * x.re;
    }
}
