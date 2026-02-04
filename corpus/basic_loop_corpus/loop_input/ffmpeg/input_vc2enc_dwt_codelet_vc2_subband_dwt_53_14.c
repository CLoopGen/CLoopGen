#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

int x;
dwtcoef *synthl;
ptrdiff_t synth_width;

void init_vars() {
    synth_width = 67108864 / sizeof(dwtcoef);  // ~256MB total data, adjusted for dwtcoef size
    synthl = (dwtcoef*)aligned_alloc(32, 2 * synth_width * sizeof(dwtcoef));
    if (!synthl) {
        exit(1);
    }
    for (ptrdiff_t i = 0; i < 2 * synth_width; i++) {
        synthl[i] = (dwtcoef)(i & 0xFF);
    }
    x = 0;
}