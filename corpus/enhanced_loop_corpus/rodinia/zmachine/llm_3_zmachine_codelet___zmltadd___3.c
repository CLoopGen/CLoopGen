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
    // Variant 2: Reverse sequential access (backward traversal)
    for (i = len - 1; i >= 0; i--) {
        t_re = zp1[i].re + s.re * zp2[i].re - s.im * zp2[i].im;
        t_im = zp1[i].im + s.re * zp2[i].im + s.im * zp2[i].re;
        zp1[i].re = t_re;
        zp1[i].im = t_im;
    }
}
