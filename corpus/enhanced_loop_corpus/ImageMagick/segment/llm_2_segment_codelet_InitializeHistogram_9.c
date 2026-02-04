#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int Blue;
extern  int Green;
extern  int Red;
extern ssize_t **histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D access pattern
    // Assuming histogram is organized as [3][256] and Red, Green, Blue are 0, 1, 2 respectively
    // We rewrite the zero-initialization in a consecutive manner for better cache locality
    ssize_t *base_r = histogram[Red];
    ssize_t *base_g = histogram[Green];
    ssize_t *base_b = histogram[Blue];

    for (i = 0; i <= 255; i++) {
        base_r[i] = 0;
        base_g[i] = 0;
        base_b[i] = 0;
    }
}
