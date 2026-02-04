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
    src_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    dst_capacity = src_size + 65536; // Extra space to accommodate expansion

    src_buf = aligned_alloc(32, src_size);
    dst_buf = aligned_alloc(32, dst_capacity);

    if (!src_buf || !dst_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source buffer with controlled pattern to ensure safe memory accesses
    for (size_t idx = 0; idx < src_size; idx++) {
        if (idx >= 2 && (idx % 1000 == 0)) {
            // Create a match for the condition: src[0]==3, src[-1]==0, src[-2]==0, and next < 4
            src_buf[idx - 2] = 0;
            src_buf[idx - 1] = 0;
            src_buf[idx + 0] = 3;
            if (idx + 1 < src_size) {
                src_buf[idx + 1] = 2; // Ensure src[1] < 4
            }
            idx += 1; // Skip next byte to avoid overlap
        } else {
            src_buf[idx] = rand() % 254 + 1; // Avoid 0 and 3 in random to reduce accidental matches
        }
    }

    // Ensure first two bytes are not part of any pattern that could trigger condition
    src_buf[0] = 1;
    src_buf[1] = 1;

    // Ensure last byte doesn't cause out-of-bounds access when checking src[1]
    if (src_size > 1) {
        src_buf[src_size - 1] = 1;
    }

    src = src_buf;
    dst = dst_buf;
    size = (int)src_size;
    dsize = 0;
}