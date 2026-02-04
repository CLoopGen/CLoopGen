#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    complex *base;
    complex **me;
} ZMAT;

extern ZMAT *A;
extern int k;
extern int k_min;
extern int k_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *re_ptr = &A->me[k_min + 2][k_min].re;
    double *im_ptr = &A->me[k_min + 2][k_min].im;
    for (int i = k_min; i <= k_max - 2; i++) {
        *(re_ptr + (i - k_min) * (A->max_n * sizeof(complex) / sizeof(double)) + i) = 0.;
        *(im_ptr + (i - k_min) * (A->max_n * sizeof(complex) / sizeof(double)) + i) = 0.;
    }
}
