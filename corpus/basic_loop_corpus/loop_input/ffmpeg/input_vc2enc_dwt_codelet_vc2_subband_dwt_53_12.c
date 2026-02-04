#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

int height = 512;
int x;
int y;
ptrdiff_t synth_width = 1024;
dwtcoef *synthl;

void init_vars() {
    size_t total_elements = (size_t)(height * 2) * (size_t)synth_width;
    dwtcoef *data = (dwtcoef*)calloc(total_elements, sizeof(dwtcoef));
    if (!data) {
        exit(1);
    }

    for (size_t i = 0; i < total_elements; i++) {
        data[i] = rand() % 1000;
    }

    synthl = data;
}