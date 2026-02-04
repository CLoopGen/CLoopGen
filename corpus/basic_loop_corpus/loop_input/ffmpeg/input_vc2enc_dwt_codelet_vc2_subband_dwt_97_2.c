#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

int width = 512;
int x;
int y;
dwtcoef *synthl;
ptrdiff_t synth_width = 1024;
ptrdiff_t synth_height = 512;

void init_vars() {
    const size_t total_size = synth_width * synth_height * sizeof(dwtcoef);
    dwtcoef *data_pool = (dwtcoef *)calloc(total_size, 1);
    if (!data_pool) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    synthl = data_pool;
}