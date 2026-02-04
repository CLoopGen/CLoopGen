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
for (x = 0; x <= 255; x++) {
    sum = 0.;
    for (u = 0; u <= 255; u += 4) {
        sum += (double)histogram[u] * gamma[(x - u) < 0 ? -(x - u) : (x - u)];
        if (u + 1 <= 255) sum += (double)histogram[u + 1] * gamma[(x - (u + 1)) < 0 ? -(x - (u + 1)) : (x - (u + 1))];
        if (u + 2 <= 255) sum += (double)histogram[u + 2] * gamma[(x - (u + 2)) < 0 ? -(x - (u + 2)) : (x - (u + 2))];
        if (u + 3 <= 255) sum += (double)histogram[u + 3] * gamma[(x - (u + 3)) < 0 ? -(x - (u + 3)) : (x - (u + 3))];
    }
    scale_histogram[x] = alpha * sum;
}
}
