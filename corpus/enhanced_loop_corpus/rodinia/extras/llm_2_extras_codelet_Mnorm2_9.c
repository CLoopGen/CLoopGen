#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern int i;
extern double invnorm;
extern double sum;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, then handle remainder)
    int stride = 2;
    int i;
    for (i = 0; i < len; i += stride) {
        tmp = x[i] * invnorm;
        sum += tmp * tmp;
    }
    // Handle odd-sized arrays if len is not a multiple of stride
    if (len % stride != 0) {
        i = len - 1;
        tmp = x[i] * invnorm;
        sum += tmp * tmp;
    }
}
