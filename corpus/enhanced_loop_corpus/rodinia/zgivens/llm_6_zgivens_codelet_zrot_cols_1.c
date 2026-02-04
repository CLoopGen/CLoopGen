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
    complex temp_x, temp_y;
    for (j = 0; j < mat->m; j++) {
        temp_x = out->me[j][i];
        temp_y = out->me[j][k];
        out->me[j][i].re = c * temp_x.re - s.re * temp_y.re - s.im * temp_y.im;
        out->me[j][i].im = c * temp_x.im - s.re * temp_y.im + s.im * temp_y.re;
        out->me[j][k].re = c * temp_y.re + s.re * temp_x.re - s.im * temp_x.im;
        out->me[j][k].im = c * temp_y.im + s.re * temp_x.im + s.im * temp_x.re;
    }
}
