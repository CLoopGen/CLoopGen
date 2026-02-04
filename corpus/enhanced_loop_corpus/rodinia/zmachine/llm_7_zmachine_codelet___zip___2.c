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
    double re_accum = sum.re;
    double im_accum = sum.im;
    for (i = 0; i < len; i++) {
        re_accum += zp1[i].re * zp2[i].re - zp1[i].im * zp2[i].im;
        im_accum += zp1[i].re * zp2[i].im + zp1[i].im * zp2[i].re;
    }
    sum.re = re_accum;
    sum.im = im_accum;
}
