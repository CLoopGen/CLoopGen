#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct YuvPixel {
    int8_t y;
    int8_t v;
    int8_t u;
} YuvPixel;

YuvPixel *p;
int i;
int j;

void init_vars() {
    const size_t data_size = 1 << 20;
    p = aligned_alloc(32, data_size * sizeof(YuvPixel));
    if (!p) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        p[idx].y = (int8_t)(rand() % 256 - 128);
        p[idx].v = (int8_t)(rand() % 256 - 128);
        p[idx].u = (int8_t)(rand() % 256 - 128);
    }

    i = 0;
    j = 0;
}