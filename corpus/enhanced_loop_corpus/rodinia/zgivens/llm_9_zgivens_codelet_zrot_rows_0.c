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
// Reduce arithmetic operations by precomputing common subexpressions and reducing complexity
double s_re_kj_re, s_im_kj_im, s_re_kj_im, s_im_kj_re;
for (j = 0; j < mat->n; j++) {
    // Reuse intermediate calculations to reduce total operations
    s_re_kj_re = s.re * out->me[k][j].re;
    s_im_kj_im = s.im * out->me[k][j].im;
    s_re_kj_im = s.re * out->me[k][j].im;
    s_im_kj_re = s.im * out->me[k][j].re;

    temp1.re = c * out->me[i][j].re - s_re_kj_re + s_im_kj_im;
    temp1.im = c * out->me[i][j].im - s_re_kj_im - s_im_kj_re;
    temp2.re = c * out->me[k][j].re + s.re * out->me[i][j].re + s.im * out->me[i][j].im;
    temp2.im = c * out->me[k][j].im + s.re * out->me[i][j].im - s.im * out->me[i][j].re;

    out->me[i][j] = temp1;
    out->me[k][j] = temp2;
}
}
