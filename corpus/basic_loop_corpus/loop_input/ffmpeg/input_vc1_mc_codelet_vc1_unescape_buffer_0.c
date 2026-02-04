#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int size;
uint8_t *dst;
int dsize;
int i;

static uint8_t src_buffer[134217728]; // 128MB
static uint8_t dst_buffer[134217728]; // 128MB

void init_vars() {
    size = 134217728; // 128MB of input data for ~0.01 sec runtime on modern CPU
    dsize = 0;
    i = 0;
    src = src_buffer;
    dst = dst_buffer;

    // Initialize src_buffer with safe values to prevent out-of-bounds access
    for (int idx = 0; idx < size; idx++) {
        if (idx >= 2 && idx < size - 1) {
            // Create occasional pattern: [non-zero, 0, 0, 3] followed by value < 4
            if (idx % 16 == 3) {
                src_buffer[idx - 3] = 1;
                src_buffer[idx - 2] = 0;
                src_buffer[idx - 1] = 0;
                src_buffer[idx] = 3;
                if (idx + 1 < size) {
                    src_buffer[idx + 1] = 2; // < 4, triggers condition
                }
                idx += 1;
            } else {
                src_buffer[idx] = rand() % 254 + 1; // Avoid 0 and 3 in random to reduce accidental triggers
            }
        } else {
            src_buffer[idx] = rand() % 256;
        }
    }

    // Ensure first two elements are not part of triggering pattern
    src_buffer[0] = 1;
    src_buffer[1] = 1;

    // Ensure last element doesn't cause overflow
    src_buffer[size - 1] = 1;
}