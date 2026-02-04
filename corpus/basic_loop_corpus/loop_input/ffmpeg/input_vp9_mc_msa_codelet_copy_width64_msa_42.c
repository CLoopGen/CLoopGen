#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec runtime estimate

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

static uint8_t src_data[DATA_SIZE];
static uint8_t dst_data[DATA_SIZE];

void init_vars() {
    const int alignment = 32;
    size_t src_addr = (size_t)src_data;
    size_t dst_addr = (size_t)dst_data;

    // Align to 32-byte boundary
    src = (uint8_t*)(((src_addr + alignment - 1) / alignment) * alignment);
    dst = (uint8_t*)(((dst_addr + alignment - 1) / alignment) * alignment);

    // Leave enough room after alignment
    size_t available_src_size = DATA_SIZE - (src - src_data);
    size_t available_dst_size = DATA_SIZE - (dst - dst_data);

    // Use conservative dimensions: assume 4 rows per iteration, each with stride
    src_stride = 4096; // Large enough stride to avoid overlap
    dst_stride = 4096;

    // Ensure we can do at least several iterations without OOB access
    int min_iterations = 1000;
    int rows_needed = (min_iterations * 4); // 4 src/dst updates per loop

    // Adjust height so that (height >> 2) gives reasonable loop count
    height = rows_needed;

    // Fill source data with non-zero pattern for visibility
    for (size_t i = 0; i < available_src_size; i += src_stride) {
        for (int j = 0; j < 32 && (i + j) < available_src_size; ++j) {
            src[i + j] = (uint8_t)(i ^ j);
        }
    }

    // Initialize destination
    for (size_t i = 0; i < available_dst_size; i += dst_stride) {
        for (int j = 0; j < 32 && (i + j) < available_dst_size; ++j) {
            dst[i + j] = 0;
        }
    }

    cnt = 0;
}