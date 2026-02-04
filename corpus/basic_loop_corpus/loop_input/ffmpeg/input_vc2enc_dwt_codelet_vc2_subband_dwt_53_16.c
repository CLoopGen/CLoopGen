#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

int x;
dwtcoef *synthl;
ptrdiff_t synth_width;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024;
    synth_width = 16384;
    size_t array_elements = total_size / sizeof(dwtcoef);
    if (array_elements <= 2 * (size_t)synth_width) {
        synth_width = array_elements / 3;
    }
    dwtcoef *temp = aligned_alloc(32, array_elements * sizeof(dwtcoef));
    synthl = temp + synth_width;
    for (size_t i = 0; i < array_elements; i++) {
        temp[i] = rand() % 1000;
    }
}