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
        if (zp[i].re == 0.0 && zp[i].im == 0.0) {
            out[i].re = 0.0;
            out[i].im = 0.0;
            continue;
        }
        t_re = s.re * zp[i].re - s.im * zp[i].im;
        t_im = s.re * zp[i].im + s.im * zp[i].re;
        out[i].re = t_re;
        out[i].im = t_im;
    }
}
