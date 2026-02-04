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
extern complex s;
extern int len;
extern int i;
extern double t_re;
extern double t_im;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < len; i += 2) {
        t_re = zp1[i].re + s.re * zp2[i].re + s.im * zp2[i].im;
        t_im = zp1[i].im - s.re * zp2[i].im + s.im * zp2[i].re;
        zp1[i].re = t_re;
        zp1[i].im = t_im;
    }
}
