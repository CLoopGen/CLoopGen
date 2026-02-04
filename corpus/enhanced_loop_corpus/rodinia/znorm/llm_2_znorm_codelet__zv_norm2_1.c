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

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern ZVEC *x;
extern VEC *scale;
extern int i;
extern int dim;
extern double s;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < dim; i += 2) {
        s = scale->ve[i];
        sum += (s == 0.) ? ((x->ve[i].re) * (x->ve[i].re)) + ((x->ve[i].im) * (x->ve[i].im)) : (((x->ve[i].re) * (x->ve[i].re)) + ((x->ve[i].im) * (x->ve[i].im))) / ((s) * (s));
        if (i + 1 < dim) {
            s = scale->ve[i + 1];
            sum += (s == 0.) ? ((x->ve[i + 1].re) * (x->ve[i + 1].re)) + ((x->ve[i + 1].im) * (x->ve[i + 1].im)) : (((x->ve[i + 1].re) * (x->ve[i + 1].re)) + ((x->ve[i + 1].im) * (x->ve[i + 1].im))) / ((s) * (s));
        }
    }
}
