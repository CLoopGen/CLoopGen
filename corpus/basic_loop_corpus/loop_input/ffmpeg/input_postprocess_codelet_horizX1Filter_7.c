#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128MB for ~0.01s runtime estimate

uint8_t *src;
int stride = 16;
int QP = 50;
int y;

static uint8_t *buffer;

void init_vars() {
    buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < DATA_SIZE; ++i) {
        buffer[i] = rand() % 256;
    }

    src = buffer + 8; // Ensure src[1..6] are valid; leave padding at beginning
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}