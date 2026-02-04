#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024 * 1024)

uint8_t *src;
int32_t src_stride;
uint8_t *ref;
int32_t ref_stride;
int32_t height;
int32_t ht_cnt;

void init_vars() {
    src_stride = 4096;
    ref_stride = 4096;
    height = 32768;

    size_t src_size = height * src_stride;
    size_t ref_size = height * ref_stride;

    src = aligned_alloc(32, src_size);
    ref = aligned_alloc(32, ref_size);

    if (!src || !ref) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    uint64_t seed = time(NULL);
    for (size_t i = 0; i < src_size; i++) {
        src[i] = (uint8_t)(seed >> (i % 56));
        seed *= 6364136223846793005ULL;
    }
    seed = time(NULL) ^ 0xdeadbeef;
    for (size_t i = 0; i < ref_size; i++) {
        ref[i] = (uint8_t)(seed >> (i % 48));
        seed *= 6364136223846793005ULL;
    }
}