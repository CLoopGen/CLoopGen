#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *sum;
extern  float *t;
extern  float *c;
extern ptrdiff_t len;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Restructure data access to process real and imaginary parts in separate sequential loops
    // to improve spatial locality and potential vectorization

    float *sum_re = &sum[0];
    float *sum_im = &sum[1];
    float *t_re = &t[0];
    float *t_im = &t[1];
    float *c_re = &c[0];
    float *c_im = &c[1];

    for (n = 0; n < len; n++) {
        sum_re[2 * n] += t_re[2 * n] * c_re[2 * n] - t_im[2 * n] * c_im[2 * n];
        sum_im[2 * n] += t_re[2 * n] * c_im[2 * n] + t_im[2 * n] * c_re[2 * n];
    }
}
