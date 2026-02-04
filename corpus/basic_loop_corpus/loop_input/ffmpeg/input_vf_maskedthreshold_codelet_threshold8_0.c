#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *src;
uint8_t *ref;
uint8_t *dst;
int threshold;
int w;

static uint8_t *src_buf;
static uint8_t *ref_buf;
static uint8_t *dst_buf;

void init_vars() {
    w = 64 * 1024 * 1024; // 64 million elements to target ~0.01s runtime on modern CPU

    size_t data_size = w * sizeof(uint8_t);

    src_buf = aligned_alloc(32, data_size);
    ref_buf = aligned_alloc(32, data_size);
    dst_buf = aligned_alloc(32, data_size);

    if (!src_buf || !ref_buf || !dst_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < w; i++) {
        src_buf[i] = rand() % 256;
        ref_buf[i] = rand() % 256;
    }
    memset(dst_buf, 0, data_size);

    src = src_buf;
    ref = ref_buf;
    dst = dst_buf;

    threshold = 10;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buf);
    free(ref_buf);
    free(dst_buf);
}