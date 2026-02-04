#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern complex *zp1;
extern complex *zp2;
extern int len;
extern complex sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < len * 2; j += 2) {
    int idx = j / 2;
    double a_re = zp1[idx].re;
    double a_im = zp1[idx].im;
    double b_re = zp2[idx].re;
    double b_im = zp2[idx].im;
    sum.re += a_re * b_re - a_im * b_im;
    sum.im += a_re * b_im + a_im * b_re;
}
}
