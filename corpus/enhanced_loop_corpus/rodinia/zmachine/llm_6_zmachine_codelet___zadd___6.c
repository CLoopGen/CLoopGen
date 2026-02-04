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
    double temp_re, temp_im;
    for (i = 0; i < len; i++) {
        temp_re = zp1[i].re + zp2[i].re;
        temp_im = zp1[i].im + zp2[i].im;
        out[i].re = temp_re;
        out[i].im = temp_im;
    }
}
