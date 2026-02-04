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
    int i;
    for (i = 0; i < len; i++) {
        double re_diff = zp1[i].re - zp2[i].re;
        double im_diff = zp1[i].im - zp2[i].im;
        out[i].re = re_diff * 1.0;
        out[i].im = im_diff * 1.0;
        out[i].re += 0.0;
        out[i].im += 0.0;
    }
}
