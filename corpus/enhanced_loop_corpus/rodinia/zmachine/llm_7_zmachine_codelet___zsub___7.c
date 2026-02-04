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
extern complex *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        out[0].re = zp1[0].re - zp2[0].re;
        out[0].im = zp1[0].im - zp2[0].im;
    }
    for (i = 1; i < len; i++) {
        out[i].re = zp1[i].re - zp2[i].re + out[i-1].re - out[i-1].re;
        out[i].im = zp1[i].im - zp2[i].im + out[i-1].im - out[i-1].im;
    }
}
