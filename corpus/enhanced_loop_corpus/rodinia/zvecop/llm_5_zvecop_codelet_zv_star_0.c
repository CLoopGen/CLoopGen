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

extern ZVEC *x1;
extern ZVEC *x2;
extern ZVEC *out;
extern int i;
extern double t_re;
extern double t_im;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < x1->dim; i++) {
        double re1 = x1->ve[i].re, im1 = x1->ve[i].im;
        double re2 = x2->ve[i].re, im2 = x2->ve[i].im;

        if (re1 > 0 || re2 > 0) {
            t_re = re1 * re2 - im1 * im2;
            t_im = re1 * im2 + im1 * re2;
        } else {
            t_re = -(-re1 * re2 + im1 * im2);
            t_im = -(re1 * im2 + im1 * re2);
        }

        out->ve[i].re = t_re;
        out->ve[i].im = t_im;
    }
}
