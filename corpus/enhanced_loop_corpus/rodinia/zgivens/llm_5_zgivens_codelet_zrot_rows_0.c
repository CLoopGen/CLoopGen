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
if (i >= mat->m || k >= mat->m || i == k) return;
for (j = 0; j < mat->n; j++) {
    double re_i = out->me[i][j].re, im_i = out->me[i][j].im;
    double re_k = out->me[k][j].re, im_k = out->me[k][j].im;
    
    if (re_i * re_i + im_i * im_i > re_k * re_k + im_k * im_k) {
        temp1.re = c * re_i - s.re * re_k + s.im * im_k;
        temp1.im = c * im_i - s.re * im_k - s.im * re_k;
        temp2.re = c * re_k + s.re * re_i + s.im * im_i;
        temp2.im = c * im_k + s.re * im_i - s.im * re_i;
    } else {
        temp1.re = c * re_i + s.re * re_k - s.im * im_k;
        temp1.im = c * im_i + s.re * im_k + s.im * re_k;
        temp2.re = c * re_k - s.re * re_i + s.im * im_i;
        temp2.im = c * im_k - s.re * im_i - s.im * re_i;
    }
    out->me[i][j].re = temp1.re;
    out->me[i][j].im = temp1.im;
    out->me[k][j].re = temp2.re;
    out->me[k][j].im = temp2.im;
}
}
