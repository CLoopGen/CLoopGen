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
    double temp_re, temp_im;
    for (i = 0; i < x1->dim; i++) {
        temp_re = x1->ve[i].re * x2->ve[i].re - x1->ve[i].im * x2->ve[i].im;
        temp_im = x1->ve[i].re * x2->ve[i].im + x1->ve[i].im * x2->ve[i].re;
        out->ve[i].re = temp_re;
        out->ve[i].im = temp_im;
    }
}
