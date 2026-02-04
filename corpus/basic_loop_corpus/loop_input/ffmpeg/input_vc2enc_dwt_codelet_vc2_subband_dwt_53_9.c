#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

ptrdiff_t stride;
int x;
int y;
dwtcoef *synthl;
dwtcoef *datal;
ptrdiff_t synth_width;
ptrdiff_t synth_height;

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / sizeof(dwtcoef))
static dwtcoef data_buffer[DATA_SIZE_MB * ELEMENTS_PER_MB];
static dwtcoef synth_buffer[DATA_SIZE_MB * ELEMENTS_PER_MB];

void init_vars() {
    const size_t total_elements = DATA_SIZE_MB * ELEMENTS_PER_MB;
    synth_width = 4096;
    if (synth_width == 0) synth_width = 1;
    synth_height = total_elements / synth_width;
    if (synth_height == 0) synth_height = 1;
    while (((size_t)synth_width) * ((size_t)synth_height) > total_elements) {
        synth_height--;
    }

    stride = synth_width + 16;
    
    for (size_t i = 0; i < total_elements; i++) {
        data_buffer[i] = (dwtcoef)(i % 1000);
        synth_buffer[i] = 0;
    }

    datal = data_buffer;
    synthl = synth_buffer;
    x = 0;
    y = 0;
}