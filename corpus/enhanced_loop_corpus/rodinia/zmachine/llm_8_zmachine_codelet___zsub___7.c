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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            out[i].re = zp1[i].re - zp2[i].re;
            out[i].im = zp1[i].im - zp2[i].im;
            out[i+1].re = zp1[i+1].re - zp2[i+1].re;
            out[i+1].im = zp1[i+1].im - zp2[i+1].im;
        } else {
            out[i].re = zp1[i].re - zp2[i].re;
            out[i].im = zp1[i].im - zp2[i].im;
        }
    }
}
