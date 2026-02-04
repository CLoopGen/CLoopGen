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
    int stride = 2;
    if (len > 0) {
        for (i = 0; i < len; i += stride) {
            double re1 = zp1[i].re, im1 = zp1[i].im;
            double re2 = zp2[i].re, im2 = zp2[i].im;
            sum.re += re1 * re2 - im1 * im2;
            sum.im += re1 * im2 + im1 * re2;
            if (i + 1 < len) {
                re1 = zp1[i+1].re; im1 = zp1[i+1].im;
                re2 = zp2[i+1].re; im2 = zp2[i+1].im;
                sum.re += re1 * re2 - im1 * im2;
                sum.im += re1 * im2 + im1 * re2;
            }
        }
    }
}
