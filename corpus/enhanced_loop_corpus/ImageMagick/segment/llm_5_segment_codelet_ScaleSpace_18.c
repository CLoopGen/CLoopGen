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
    for (u = 0; u <= 255; u++) {
        ssize_t index = x - u;
        // Introduce early skip condition based on histogram value
        if (histogram[u] == 0) continue;
        sum += (double)histogram[u] * gamma[index < 0 ? -index : index];
    }
    scale_histogram[x] = alpha * sum;
}
}
