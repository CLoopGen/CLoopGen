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
    complex temp_sum = {0.0, 0.0};
    for (i = 0; i < len; i++) {
        double re_part = zp1[i].re * zp2[i].re - zp1[i].im * zp2[i].im;
        double im_part = zp1[i].re * zp2[i].im + zp1[i].im * zp2[i].re;
        temp_sum.re += re_part;
        temp_sum.im += im_part;
    }
    sum.re = temp_sum.re;
    sum.im = temp_sum.im;
}
