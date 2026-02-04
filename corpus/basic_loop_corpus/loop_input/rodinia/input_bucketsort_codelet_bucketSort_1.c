#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int histosize;
unsigned int *h_offsets;
float *historesult;

void init_vars() {
    histosize = 64 * 1024 * 1024 / sizeof(unsigned int);  // ~256 MB of data for h_offsets and historesult combined

    h_offsets = (unsigned int*)aligned_alloc(32, histosize * sizeof(unsigned int));
    historesult = (float*)aligned_alloc(32, histosize * sizeof(float));

    for (int i = 0; i < histosize; i++) {
        h_offsets[i] = (unsigned int)(i * 31);
    }
}