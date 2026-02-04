#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

int x;
int y;
dwtcoef *synthl;
ptrdiff_t synth_width;
ptrdiff_t synth_height;

void init_vars() {
    synth_width = 4096;
    synth_height = 4096;

    size_t total_elements = (size_t)synth_height * synth_width;
    synthl = (dwtcoef*)calloc(total_elements, sizeof(dwtcoef));

    if (!synthl) {
        exit(1);
    }

    for (size_t i = 0; i < total_elements; i++) {
        synthl[i] = rand() % 1000;
    }
}