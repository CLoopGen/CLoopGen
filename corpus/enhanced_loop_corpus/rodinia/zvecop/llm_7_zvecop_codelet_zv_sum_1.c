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



void loop(){
    sum.re = 0.0;
    sum.im = 0.0;
    for (i = 0; i < x->dim; i += 2) {
        sum.re += x->ve[i].re;
        sum.im += x->ve[i].im;
        if (i + 1 < x->dim) {
            sum.re += x->ve[i+1].re;
            sum.im += x->ve[i+1].im;
        }
    }
}
