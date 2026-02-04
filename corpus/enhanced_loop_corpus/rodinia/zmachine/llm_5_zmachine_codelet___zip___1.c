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
    for (i = 0; i < len; i++) {
        if (zp1[i].re == 0.0 && zp1[i].im == 0.0) continue;
        if (zp2[i].re == 0.0 && zp2[i].im == 0.0) continue;
        sum.re += zp1[i].re * zp2[i].re + zp1[i].im * zp2[i].im;
        sum.im += zp1[i].re * zp2[i].im - zp1[i].im * zp2[i].re;
    }
}
