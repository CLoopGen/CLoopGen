#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int dim;
    u_int max_dim;
    complex *ve;
} ZVEC;

extern ZVEC *x;
extern int i;
extern complex sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    sum.re = 0.0;
    sum.im = 0.0;
    for (i = 0; i < x->dim && i < x->max_dim; i++) {
        double re_sq = x->ve[i].re * x->ve[i].re;
        double im_sq = x->ve[i].im * x->ve[i].im;
        sum.re += re_sq - im_sq;
        sum.im += 2.0 * x->ve[i].re * x->ve[i].im;
    }
}
