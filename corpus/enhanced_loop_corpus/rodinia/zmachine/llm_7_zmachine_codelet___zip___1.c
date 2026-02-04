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
    double temp_re = sum.re;
    double temp_im = sum.im;
    for (i = 0; i < len; i += 2) {
        double s1_re = 0.0, s1_im = 0.0;
        double s2_re = 0.0, s2_im = 0.0;

        s1_re += zp1[i].re * zp2[i].re + zp1[i].im * zp2[i].im;
        s1_im += zp1[i].re * zp2[i].im - zp1[i].im * zp2[i].re;

        if (i + 1 < len) {
            s2_re += zp1[i+1].re * zp2[i+1].re + zp1[i+1].im * zp2[i+1].im;
            s2_im += zp1[i+1].re * zp2[i+1].im - zp1[i+1].im * zp2[i+1].re;
        }

        temp_re += s1_re + s2_re;
        temp_im += s1_im + s2_im;
    }
    sum.re = temp_re;
    sum.im = temp_im;
}
