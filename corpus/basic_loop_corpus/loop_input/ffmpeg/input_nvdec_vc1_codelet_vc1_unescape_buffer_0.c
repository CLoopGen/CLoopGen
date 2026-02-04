#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int size;
uint8_t *dst;
int dsize;
int i;

static uint8_t src_buffer[134217728]; // 128 MB
static uint8_t dst_buffer[134217728]; // 128 MB

void init_vars() {
    size = 134217728; // 128 MB of input data for ~0.01 sec runtime on modern CPU
    dsize = 0;
    i = 0;
    src = src_buffer;
    dst = dst_buffer;

    // Initialize src with sample data to ensure safe access including edge checks
    for (int idx = 0; idx < size; ++idx) {
        if (idx >= 2 && idx < size - 1) {
            // Create some occurrences where pattern matches: [0][0][3][x<4]
            if (idx % 10000 == 0) {
                src_buffer[idx - 2] = 0;
                src_buffer[idx - 1] = 0;
                src_buffer[idx]     = 3;
                src_buffer[idx + 1] = (idx % 3) + 1; // 1, 2, or 3 (<4)
                ++idx; // skip next since we set it already
            } else {
                src_buffer[idx] = rand() % 256;
            }
        } else {
            src_buffer[idx] = rand() % 256;
        }
    }

    // Ensure boundaries are safe for [-2], [-1], [0], [1] accesses within loop bounds
    // The loop condition and inner checks already guard against out-of-bounds
}