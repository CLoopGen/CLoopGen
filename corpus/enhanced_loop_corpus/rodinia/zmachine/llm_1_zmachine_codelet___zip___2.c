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
for (i = 0; i < len; i += 2) {
    int end = (i + 1 < len) ? i + 2 : i + 1;
    for (int k = i; k < end; k++) {
        sum.re += zp1[k].re * zp2[k].re - zp1[k].im * zp2[k].im;
        sum.im += zp1[k].re * zp2[k].im + zp1[k].im * zp2[k].re;
    }
}
}
