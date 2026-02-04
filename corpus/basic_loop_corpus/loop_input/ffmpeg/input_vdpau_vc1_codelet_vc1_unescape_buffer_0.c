#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int size;
uint8_t *dst;
int dsize;
int i;

static uint8_t *src_buf;
static uint8_t *dst_buf;
static size_t src_size;
static size_t dst_capacity;

void init_vars() {
    src_size = 64 * 1024 * 1024; // 64 MB input for ~0.01 sec runtime on modern CPU
    dst_capacity = src_size + 65536; // Extra space to accommodate expansion

    src_buf = (uint8_t *)calloc(src_size, sizeof(uint8_t));
    dst_buf = (uint8_t *)malloc(dst_capacity * sizeof(uint8_t));

    if (!src_buf || !dst_buf) {
        free(src_buf);
        free(dst_buf);
        exit(1);
    }

    // Initialize source data with a repeating pattern that occasionally triggers the condition
    for (size_t idx = 0; idx < src_size; idx++) {
        if (idx >= 2 && idx < src_size - 1 &&
            (idx % 1024 == 100)) { // Create sparse matches every 1KB-ish
            src_buf[idx - 2] = 0;
            src_buf[idx - 1] = 0;
            src_buf[idx]     = 3;
            src_buf[idx + 1] = 2; // Must be < 4 to satisfy src[1] < 4
            idx += 1; // Skip next since we set two values
        } else {
            src_buf[idx] = (uint8_t)((idx * 17) & 0xFF); // Fill rest with non-matching pattern
        }
    }

    // Set up external variables
    src = src_buf;
    size = (int)src_size;
    dst = dst_buf;
    dsize = 0;
}