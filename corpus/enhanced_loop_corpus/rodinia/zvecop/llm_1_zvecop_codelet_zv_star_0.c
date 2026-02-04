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
    for (i = 0; i < x1->dim; i += 2) {
        for (int k = 0; k < 2 && (i + k) < x1->dim; k++) {
            int idx = i + k;
            t_re = x1->ve[idx].re * x2->ve[idx].re - x1->ve[idx].im * x2->ve[idx].im;
            t_im = x1->ve[idx].re * x2->ve[idx].im + x1->ve[idx].im * x2->ve[idx].re;
            out->ve[idx].re = t_re;
            out->ve[idx].im = t_im;
        }
    }
}
