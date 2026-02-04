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
    if (len <= 0) return;
    double prev_t_re = zp1[0].re;
    double prev_t_im = zp1[0].im;
    t_re = prev_t_re + s.re * zp2[0].re - s.im * zp2[0].im;
    t_im = prev_t_im + s.re * zp2[0].im + s.im * zp2[0].re;
    zp1[0].re = t_re;
    zp1[0].im = t_im;

    for (i = 1; i < len; i++) {
        double current_re = zp1[i].re;
        double current_im = zp1[i].im;
        t_re = current_re + s.re * zp2[i].re - s.im * zp2[i].im;
        t_im = current_im + s.re * zp2[i].im + s.im * zp2[i].re;
        zp1[i].re = t_re;
        zp1[i].im = t_im;
    }
}
