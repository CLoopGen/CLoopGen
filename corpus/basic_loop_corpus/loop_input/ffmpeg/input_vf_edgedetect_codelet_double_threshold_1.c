#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int low = 50;
int high = 150;
int w = 4096;
int h = 64;
int dst_linesize = 4096;
int src_linesize = 4096;
uint8_t *dst;
uint8_t *src;
int i;
int j;

void init_vars() {
    const size_t total_size = (size_t)w * h;
    const size_t padded_size = total_size + 2 * src_linesize + 2; // Add padding for safe neighbor access

    src = aligned_alloc(32, padded_size * sizeof(uint8_t));
    dst = aligned_alloc(32, padded_size * sizeof(uint8_t));

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < total_size; idx++) {
        src[idx] = (uint8_t)(rand() % 256);
    }

    memset(dst, 0, padded_size * sizeof(uint8_t));

    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            size_t idx = row * src_linesize + col;
            src[idx] = (uint8_t)(rand() % 256);
        }
    }
}