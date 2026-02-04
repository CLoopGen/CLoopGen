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
extern complex temp1;
extern complex temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    complex *row_i = out->me[i];
    complex *row_k = out->me[k];
    u_int n = mat->n;
    for (j = 0; j < n; j++) {
        temp1.re = c * row_i[j].re - s.re * row_k[j].re + s.im * row_k[j].im;
        temp1.im = c * row_i[j].im - s.re * row_k[j].im - s.im * row_k[j].re;
        temp2.re = c * row_k[j].re + s.re * row_i[j].re + s.im * row_i[j].im;
        temp2.im = c * row_k[j].im + s.re * row_i[j].im - s.im * row_i[j].re;
        row_i[j] = temp1;
        row_k[j] = temp2;
    }
}
