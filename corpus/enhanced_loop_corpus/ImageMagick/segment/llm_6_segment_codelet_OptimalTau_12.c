#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ZeroCrossing {
    double tau;
    double histogram[256];
    short crossings[256];
} ZeroCrossing;

extern  ssize_t *histogram;
extern ssize_t i;
extern ssize_t j;
extern ZeroCrossing *zero_crossing;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *hist = zero_crossing[i].histogram;
    ssize_t *src = histogram;
    for (j = 0; j <= 255; j += 4) {
        hist[j]     = (double)src[j];
        hist[j + 1] = (double)src[j + 1];
        hist[j + 2] = (double)src[j + 2];
        hist[j + 3] = (double)src[j + 3];
    }
}
