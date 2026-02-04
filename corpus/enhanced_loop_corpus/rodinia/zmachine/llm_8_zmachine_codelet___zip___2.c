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
int i1;
for (i1 = 0; i1 < len; i1 += 2) {
    if (i1 + 1 < len) {
        sum.re += zp1[i1].re * zp2[i1].re - zp1[i1].im * zp2[i1].im;
        sum.im += zp1[i1].re * zp2[i1].im + zp1[i1].im * zp2[i1].re;
        sum.re += zp1[i1+1].re * zp2[i1+1].re - zp1[i1+1].im * zp2[i1+1].im;
        sum.im += zp1[i1+1].re * zp2[i1+1].im + zp1[i1+1].im * zp2[i1+1].re;
    } else {
        sum.re += zp1[i1].re * zp2[i1].re - zp1[i1].im * zp2[i1].im;
        sum.im += zp1[i1].re * zp2[i1].im + zp1[i1].im * zp2[i1].re;
    }
}
}
