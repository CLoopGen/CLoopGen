#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

int x;
dwtcoef *synthl;
ptrdiff_t synth_width;

void init_vars() {
    synth_width = 1 << 20;  // Approximately 4 million elements, ~16MB for dwtcoef (4 bytes each)

    synthl = (dwtcoef*)aligned_alloc(64, sizeof(dwtcoef) * (synth_width * 3));
    if (!synthl) {
        exit(1);
    }

    dwtcoef *base = synthl + synth_width;
    for (ptrdiff_t i = 0; i < synth_width; i++) {
        base[i] = i & 0xFF;
    }
    for (ptrdiff_t i = 0; i < synth_width; i++) {
        base[-synth_width + i] = (i + 1) & 0xFF;
    }
    for (ptrdiff_t i = 0; i < synth_width; i++) {
        base[synth_width + i] = (i + 2) & 0xFF;
    }

    synthl = base;
    x = 0;
}