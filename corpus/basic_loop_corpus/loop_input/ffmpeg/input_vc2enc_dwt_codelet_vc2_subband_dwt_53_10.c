#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

int width = 512;
int x;
int y;
ptrdiff_t synth_width;
ptrdiff_t synth_height;
dwtcoef *synthl;

void init_vars() {
    synth_width = 2 * width;
    synth_height = 512;

    size_t total_size = synth_width * synth_height;
    dwtcoef *data = (dwtcoef*)calloc(total_size, sizeof(dwtcoef));
    
    if (!data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        data[i] = rand() % 1000;
    }

    synthl = data;
}