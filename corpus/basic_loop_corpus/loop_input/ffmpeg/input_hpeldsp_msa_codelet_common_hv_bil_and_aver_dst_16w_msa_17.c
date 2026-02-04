#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
uint8_t height;
uint8_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    // Allocate approximately 64MB for src and dst to ensure loop runtime around 0.01s
    size_t buffer_size = 64 * 1024 * 1024;
    src_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, buffer_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    // Initialize buffers to zero to avoid undefined behavior
    memset(src_buffer, 0, buffer_size);
    memset(dst_buffer, 0, buffer_size);

    // Set stride values to 1024 (common cache-conscious alignment)
    src_stride = 1024;
    dst_stride = 1024;

    // Set height so that (height >> 3) results in a reasonable loop count
    // We want the loop to run enough times to take ~0.01s, but original loop does (height >> 3) iterations
    // Given the empty nature of the loop, we need large height to induce measurable delay
    height = 200; // This gives 25 iterations of outer loop

    // Initialize src and dst pointers to middle of buffers to allow safe access with strides
    // Ensure we don't go out of bounds when accessing up to (height>>3)*8*src_stride offset
    size_t src_offset = 16 * src_stride; // Leave margin
    size_t dst_offset = 16 * dst_stride;

    if (src_offset + ((height >> 3) * 8 * src_stride) + 64 > buffer_size ||
        dst_offset + ((height >> 3) * 8 * dst_stride) + 64 > buffer_size) {
        exit(1);
    }

    src = src_buffer + src_offset;
    dst = dst_buffer + dst_offset;

    loop_cnt = 0;
}

// Definitions must remain as global extern references
uint8_t *src = NULL;
int32_t src_stride = 0;
uint8_t *dst = NULL;
int32_t dst_stride = 0;
uint8_t height = 0;
uint8_t loop_cnt = 0;