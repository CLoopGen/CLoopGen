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

extern ZMAT *mat;
extern ZMAT *out;
extern int i;
extern int k;
extern double c;
extern complex s;
extern u_int j;
extern complex x;
extern complex y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int outer;
    for (outer = 0; outer < mat->m; outer++) {
        j = outer;
        {
            x = out->me[j][i];
            y = out->me[j][k];
            out->me[j][i].re = c * x.re - s.re * y.re - s.im * y.im;
            out->me[j][i].im = c * x.im - s.re * y.im + s.im * y.re;
            out->me[j][k].re = c * y.re + s.re * x.re - s.im * x.im;
            out->me[j][k].im = c * y.im + s.re * x.im + s.im * x.re;
        }
    }
}
