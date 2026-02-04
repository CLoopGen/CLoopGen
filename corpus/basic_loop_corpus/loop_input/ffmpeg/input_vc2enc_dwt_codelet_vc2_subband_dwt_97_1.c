#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

ptrdiff_t stride;
int x;
int y;
dwtcoef *datal;
dwtcoef *synthl;
ptrdiff_t synth_width;
ptrdiff_t synth_height;

void init_vars() {
    synth_width = 4096;
    synth_height = 64;
    stride = synth_width;

    datal = (dwtcoef*)aligned_alloc(32, synth_width * synth_height * sizeof(dwtcoef));
    synthl = (dwtcoef*)aligned_alloc(32, synth_width * synth_height * sizeof(dwtcoef));

    for (int i = 0; i < synth_width * synth_height; i++) {
        datal[i] = rand() % 1000;
        synthl[i] = 0;
    }
}