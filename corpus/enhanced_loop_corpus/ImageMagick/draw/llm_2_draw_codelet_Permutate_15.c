#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t n;
extern  ssize_t k;
extern double r;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using pointer arithmetic with stride of 2
    // We simulate a strided access by treating 'r' as if it were part of an array and updating every 2nd logical element
    // Though r is scalar, we conceptually model repeated division by even indices to reflect strided behavior
    double *base_r = &r;
    ssize_t stride = 2;
    for (i = stride; i <= (n - k); i += stride) {
        *(base_r) /= i;
    }
}
