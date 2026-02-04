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
    int i;
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            // Process two iterations at once to increase computational intensity
            double t_re1 = zp1[i].re + s.re * zp2[i].re - s.im * zp2[i].im;
            double t_im1 = zp1[i].im + s.re * zp2[i].im + s.im * zp2[i].re;
            double t_re2 = zp1[i+1].re + s.re * zp2[i+1].re - s.im * zp2[i+1].im;
            double t_im2 = zp1[i+1].im + s.re * zp2[i+1].im + s.im * zp2[i+1].re;

            zp1[i].re = t_re1;
            zp1[i].im = t_im1;
            zp1[i+1].re = t_re2;
            zp1[i+1].im = t_im2;
        } else {
            // Handle odd-length case
            t_re = zp1[i].re + s.re * zp2[i].re - s.im * zp2[i].im;
            t_im = zp1[i].im + s.re * zp2[i].im + s.im * zp2[i].re;
            zp1[i].re = t_re;
            zp1[i].im = t_im;
        }
    }
}
