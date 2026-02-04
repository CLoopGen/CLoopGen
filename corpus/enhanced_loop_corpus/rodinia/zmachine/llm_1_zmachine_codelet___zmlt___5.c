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
    int stride = 4;
    for (i = 0; i < len; i += stride) {
        for (int k = 0; k < stride; k++) {
            int idx = i + k;
            if (idx < len) {
                t_re = s.re * zp[idx].re - s.im * zp[idx].im;
                t_im = s.re * zp[idx].im + s.im * zp[idx].re;
                out[idx].re = t_re;
                out[idx].im = t_im;
            }
        }
    }
}
