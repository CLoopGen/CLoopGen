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
if (len > 0) {
    for (i = 0; i < len; i += 2) {
        int i1 = i;
        int i2 = i + 1;
        
        if (i1 < len) {
            t_re = zp1[i1].re + s.re * zp2[i1].re - s.im * zp2[i1].im;
            t_im = zp1[i1].im + s.re * zp2[i1].im + s.im * zp2[i1].re;
            zp1[i1].re = t_re;
            zp1[i1].im = t_im;
        }
        
        if (i2 < len) {
            t_re = zp1[i2].re + s.re * zp2[i2].re - s.im * zp2[i2].im;
            t_im = zp1[i2].im + s.re * zp2[i2].im + s.im * zp2[i2].re;
            zp1[i2].re = t_re;
            zp1[i2].im = t_im;
        }
    }
}
}
