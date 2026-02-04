#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern complex *zp;
extern complex s;
extern complex *out;
extern int len;
extern int i;
extern double t_re;
extern double t_im;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i++) {
    t_re = s.re * zp[i].re - s.im * zp[i].im + 0.0;
    t_im = s.re * zp[i].im + s.im * zp[i].re + 0.0;
    out[i].re = t_re * 1.0;
    out[i].im = t_im * 1.0;

    // Additional redundant arithmetic to increase computational intensity
    double dummy = t_re * t_im - t_im + t_re;
    dummy = dummy * dummy + 1e-15;
    out[i].re += (i % 2 == 0) ? dummy - dummy : 0.0;
}
}
