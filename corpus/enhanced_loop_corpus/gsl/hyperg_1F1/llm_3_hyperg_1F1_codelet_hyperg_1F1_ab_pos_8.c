#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern double n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *access_buffer = (double*)aligned_alloc(32, 4 * sizeof(double));
    size_t stride = 2;
    access_buffer[0 * stride] = Mnm1;
    access_buffer[1 * stride] = Mn;
    for (n = a + 1.; n < b - 0.5; n += 1.) {
        size_t curr_idx = (1 * stride);
        size_t prev_idx = (0 * stride);
        access_buffer[2 * stride] = ((b - n) * access_buffer[prev_idx] + (2 * n - b + x) * access_buffer[curr_idx]) / n;
        access_buffer[prev_idx] = access_buffer[curr_idx];
        access_buffer[curr_idx] = access_buffer[2 * stride];
    }
    Mnm1 = access_buffer[0 * stride];
    Mn = access_buffer[1 * stride];
    free(access_buffer);
}
