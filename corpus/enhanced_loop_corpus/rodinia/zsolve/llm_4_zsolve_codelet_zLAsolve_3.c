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
    for (i = dim - 1; i >= 0; i--) {
        double real = b_ve[i].re;
        double imag = b_ve[i].im;
        if (real != 0. || imag != 0.)
            break;
    }
}
