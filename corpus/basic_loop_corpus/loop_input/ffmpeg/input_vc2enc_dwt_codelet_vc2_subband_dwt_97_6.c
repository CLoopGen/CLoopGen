#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

int x;
dwtcoef *synthl;
ptrdiff_t synth_width;

void init_vars() {
    synth_width = 65536; // Adjusted for ~0.01s runtime: 65536 * 2 (access up to x + synth_width) = 131072 elements
    size_t total_size = 2 * synth_width; // To ensure x + synth_width is valid within loop
    synthl = (dwtcoef*)aligned_alloc(32, total_size * sizeof(dwtcoef));
    if (!synthl) {
        exit(1);
    }
    for (size_t i = 0; i < total_size; i++) {
        synthl[i] = (dwtcoef)(i % 1000);
    }
    x = 0;
}