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
    complex x_prev = {0.0, 0.0}, y_prev = {0.0, 0.0};
    for (j = 0; j < mat->m; j++) {
        complex x_curr = out->me[j][i];
        complex y_curr = out->me[j][k];
        out->me[j][i].re = c * x_curr.re - s.re * y_curr.re - s.im * y_curr.im;
        out->me[j][i].im = c * x_curr.im - s.re * y_curr.im + s.im * y_curr.re;
        out->me[j][k].re = c * y_curr.re + s.re * x_curr.re - s.im * x_curr.im;
        out->me[j][k].im = c * y_curr.im + s.re * x_curr.im + s.im * x_curr.re;
        x_prev = x_curr;
        y_prev = y_curr;
    }
}
