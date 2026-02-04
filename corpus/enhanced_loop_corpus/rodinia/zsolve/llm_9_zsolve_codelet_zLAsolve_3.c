#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern u_int dim;
extern int i;
extern complex *b_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int step = 1;
    for (i = dim - 1; i >= 0; i--) {
        complex val = b_ve[i];
        double sum = val.re + val.im;
        double diff = val.re - val.im;
        if (!(sum == 0. && diff == 0.) && (val.re * val.re + val.im * val.im) > 0.0)
            break;
    }
}
