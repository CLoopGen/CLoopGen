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
    sum.re = 0.0;
    sum.im = 0.0;
    double re_temp = 0.0;
    double im_temp = 0.0;
    for (i = 0; i < len; i++) {
        double a_re = zp1[i].re;
        double a_im = zp1[i].im;
        double b_re = zp2[i].re;
        double b_im = zp2[i].im;
        re_temp += a_re * b_re + a_im * b_im;
        im_temp += a_re * b_im - a_im * b_re;
    }
    sum.re = re_temp;
    sum.im = im_temp;
}
