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
    double s_re = s.re;
    double s_im = s.im;
    for (i = 0; i < len; i++) {
        t_re = s_re * zp[i].re - s_im * zp[i].im;
        t_im = s_re * zp[i].im + s_im * zp[i].re;
        out[i].re = t_re;
        out[i].im = t_im;
    }
}
