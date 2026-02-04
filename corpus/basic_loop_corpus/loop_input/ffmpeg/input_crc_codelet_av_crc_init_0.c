#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t AVCRC;

AVCRC *ctx;
unsigned int i;
unsigned int j;

void init_vars() {
    ctx = (AVCRC*)aligned_alloc(32, 1024 * 1024);
    if (!ctx) exit(1);

    for (size_t idx = 0; idx < (1024 * 1024) / sizeof(AVCRC); idx++) {
        ctx[idx] = (AVCRC)rand();
    }
}