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

typedef struct {
    u_int dim;
    u_int max_dim;
    complex *ve;
} ZVEC;

extern int col;
extern ZMAT *mat;
extern ZVEC *vec;
extern u_int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    complex sum;
    sum.re = 0.0;
    sum.im = 0.0;
    for (i = 0; i < mat->m; i++) {
        vec->ve[i] = mat->me[i][col];
        sum.re += vec->ve[i].re;
        sum.im += vec->ve[i].im;
    }
    // Use sum to prevent optimization away
    vec->ve[0] = sum;
}
