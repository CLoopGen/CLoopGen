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
    double temp_re, temp_im;
    for (i = 0; i < len; i++) {
        temp_re = s.re * zp2[i].re + s.im * zp2[i].im;
        temp_im = -s.re * zp2[i].im + s.im * zp2[i].re;
        zp1[i].re = zp1[i].re + temp_re;
        zp1[i].im = zp1[i].im + temp_im;
    }
}
