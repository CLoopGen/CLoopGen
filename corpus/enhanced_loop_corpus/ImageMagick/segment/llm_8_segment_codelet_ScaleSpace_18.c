#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t *histogram;
extern double *scale_histogram;
extern double alpha;
extern double *gamma;
extern double sum;
extern ssize_t u;
extern ssize_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x <= 255; x += 2) {
    sum = 0.;
    for (u = 0; u <= 127; u++)
        sum += (double)histogram[u] * gamma[((x - u) < 0 ? -(x - u) : (x - u))];
    scale_histogram[x] = alpha * sum;
    if (x + 1 <= 255)
        scale_histogram[x + 1] = alpha * sum;
}
}
