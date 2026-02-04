#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int size;
uint8_t *dst;
int dsize;
int i;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t src_size = 1 << 20; // 1MB data size for ~0.01 sec runtime
static size_t dst_size = 1 << 20;

void init_vars() {
    src_buffer = (uint8_t *)calloc(src_size, sizeof(uint8_t));
    dst_buffer = (uint8_t *)calloc(dst_size, sizeof(uint8_t));
    
    if (!src_buffer || !dst_buffer) {
        free(src_buffer);
        free(dst_buffer);
        exit(1);
    }

    // Initialize source data to trigger the condition occasionally but avoid out-of-bounds
    for (size_t idx = 0; idx < src_size; idx++) {
        if (idx >= 2 && idx < src_size - 1) {
            if ((rand() % 256) < 5) { // Rare occurrence
                src_buffer[idx - 2] = 0;
                src_buffer[idx - 1] = 0;
                src_buffer[idx]     = 3;
                src_buffer[idx + 1] = rand() % 4; // < 4 to satisfy condition
                idx += 1; // Skip next to avoid overlap
            } else {
                src_buffer[idx] = rand() % 256;
            }
        } else {
            src_buffer[idx] = rand() % 256;
        }
    }

    src = src_buffer;
    dst = dst_buffer;
    size = (int)src_size;
    dsize = 0;
}