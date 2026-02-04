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
    double s_re = s.re;
    double s_im = s.im;
    complex *local_zp1 = zp1;
    complex *local_zp2 = zp2;
    for (i = 0; i < len; i++) {
        double re_part1 = s_re * local_zp2[i].re;
        double im_part1 = s_im * local_zp2[i].im;
        double re_part2 = s_re * local_zp2[i].im;
        double im_part2 = s_im * local_zp2[i].re;
        t_re = local_zp1[i].re + re_part1 - im_part1;
        t_im = local_zp1[i].im + re_part2 + im_part2;
        local_zp1[i].re = t_re;
        local_zp1[i].im = t_im;
    }
}
