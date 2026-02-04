#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

ptrdiff_t stride;
int s;
int x;
int y;
dwtcoef *synthl;
dwtcoef *datal;
ptrdiff_t synth_width;
ptrdiff_t synth_height;

void init_vars() {
    synth_width = 4096;
    synth_height = 4096;
    stride = synth_width;
    s = 2;

    synthl = (dwtcoef*)aligned_alloc(32, synth_width * synth_height * sizeof(dwtcoef));
    datal = (dwtcoef*)aligned_alloc(32, stride * synth_height * sizeof(dwtcoef));

    for (int i = 0; i < synth_width * synth_height; i++) {
        synthl[i] = 0;
    }
    for (int i = 0; i < stride * synth_height; i++) {
        datal[i] = rand() % 1000;
    }
}