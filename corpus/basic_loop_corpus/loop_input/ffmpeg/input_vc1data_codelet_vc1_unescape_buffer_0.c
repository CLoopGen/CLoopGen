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
static size_t src_size;
static size_t dst_capacity;

void init_vars() {
    src_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    dst_capacity = src_size + 65536; // Extra space to accommodate expansion

    src_buffer = aligned_alloc(64, src_size);
    dst_buffer = aligned_alloc(64, dst_capacity);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data with a pattern that triggers the condition occasionally
    for (size_t idx = 0; idx < src_size; ++idx) {
        if (idx >= 2 && idx < src_size - 1) {
            // Create some instances where: src[0]==3, src[-1]==0, src[-2]==0, src[1]<4
            if ((idx % 1024) == 0) {
                src_buffer[idx] = 3;
                src_buffer[idx - 1] = 0;
                src_buffer[idx - 2] = 0;
                // Will set src[idx+1] below
                continue;
            }
        }
        // Fill randomly otherwise
        src_buffer[idx] = rand() & 0xFF;
    }

    // Ensure safe initialization of edge cases and dependent values
    for (size_t idx = 1; idx < src_size - 1; ++idx) {
        if (src_buffer[idx] == 3 && src_buffer[idx - 1] == 0 && src_buffer[idx - 2] == 0) {
            src_buffer[idx + 1] = rand() % 4; // Ensure src[1] < 4 when condition is met
        }
    }

    // Initialize external variables
    src = src_buffer;
    size = (int)src_size;
    dst = dst_buffer;
    dsize = 0;
}