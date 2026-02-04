#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;
uint16_t *src;
ptrdiff_t srcstride = 1024 * sizeof(uint16_t);
int8_t *filter;
int16_t *tmp;

void init_vars() {
    src = aligned_alloc(32, (height + 3) * srcstride + 8);
    tmp = aligned_alloc(32, (width + 8) * sizeof(int16_t) * (height + 3));
    filter = aligned_alloc(32, 4 * sizeof(int8_t));

    if (!src || !tmp || !filter) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < 4; i++) {
        filter[i] = (int8_t)(i + 1);
    }

    for (int i = 0; i < (height + 3) * width + 4; i++) {
        src[i] = (uint16_t)(i & 0x3FF);
    }
}