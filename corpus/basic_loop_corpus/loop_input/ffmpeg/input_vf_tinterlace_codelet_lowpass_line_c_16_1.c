#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t width;
uint16_t *dstp;
uint16_t *srcp;
uint16_t *srcp_above;
uint16_t *srcp_below;
int i;
int src_x;

void init_vars() {
    width = 32 * 1024 * 1024 / sizeof(uint16_t); // ~64MB total data, ~16MB per array

    dstp = (uint16_t*)aligned_alloc(32, width * sizeof(uint16_t));
    srcp = (uint16_t*)aligned_alloc(32, width * sizeof(uint16_t));
    srcp_above = (uint16_t*)aligned_alloc(32, width * sizeof(uint16_t));
    srcp_below = (uint16_t*)aligned_alloc(32, width * sizeof(uint16_t));

    for (i = 0; i < width; i++) {
        srcp[i] = rand() & 0xFFFF;
        srcp_above[i] = rand() & 0xFFFF;
        srcp_below[i] = rand() & 0xFFFF;
        dstp[i] = 0;
    }

    i = 0;
    src_x = 0;
}