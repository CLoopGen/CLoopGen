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
    int i;
    double s, sum_local = 0.0;
    int unroll_factor = 2;
    int remainder = dim % unroll_factor;
    
    // Unrolled loop with reduced trip count and increased arithmetic per iteration
    for (i = 0; i < dim - remainder; i += unroll_factor) {
        double s0 = scale->ve[i];
        double s1 = scale->ve[i+1];
        double re0 = x->ve[i].re, im0 = x->ve[i].im;
        double re1 = x->ve[i+1].re, im1 = x->ve[i+1].im;
        
        double norm0 = (re0 * re0) + (im0 * im0);
        double norm1 = (re1 * re1) + (im1 * im1);
        
        sum_local += (s0 == 0.0) ? norm0 : norm0 / (s0 * s0);
        sum_local += (s1 == 0.0) ? norm1 : norm1 / (s1 * s1);
    }
    
    // Handle leftover iterations
    for (; i < dim; i++) {
        s = scale->ve[i];
        sum_local += (s == 0.) ? 
            ((x->ve[i].re) * (x->ve[i].re)) + ((x->ve[i].im) * (x->ve[i].im)) : 
            (((x->ve[i].re) * (x->ve[i].re)) + ((x->ve[i].im) * (x->ve[i].im))) / ((s) * (s));
    }
    sum += sum_local;
}
