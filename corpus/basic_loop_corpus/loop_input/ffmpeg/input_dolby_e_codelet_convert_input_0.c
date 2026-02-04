#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nb_words;
int key;
uint8_t *src;
uint8_t *dst;
int i;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    nb_words = 1 << 20;  // Approximately 1 million iterations

    key = 0x12345678;

    size_t total_bytes = nb_words * 3;
    
    src_buffer = (uint8_t*)aligned_alloc(32, total_bytes);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_bytes);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < total_bytes; j++) {
        src_buffer[j] = rand() & 0xFF;
    }

    src = src_buffer;
    dst = dst_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}