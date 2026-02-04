#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *tmp;
uint16_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(uint16_t))

static int32_t *tmp_buffer;
static uint16_t *src_buffer;

void init_vars() {
    const int alignment = 64;
    size_t total_tmp_elements = TOTAL_ELEMENTS * 2; // account for stride and multiple writes
    
    // Allocate aligned memory to avoid padding issues and allow vectorization
    if (posix_memalign((void**)&tmp_buffer, alignment, total_tmp_elements * sizeof(int32_t)) != 0) {
        exit(1);
    }
    if (posix_memalign((void**)&src_buffer, alignment, (TOTAL_ELEMENTS + 5) * sizeof(uint16_t)) != 0) {
        exit(1);
    }

    // Initialize buffers with non-zero values for realistic computation
    for (size_t j = 0; j < TOTAL_ELEMENTS + 5; j++) {
        src_buffer[j] = (uint16_t)(j % 1000);
    }
    for (size_t j = 0; j < total_tmp_elements; j++) {
        tmp_buffer[j] = 0;
    }

    // Set external variables
    tmp = tmp_buffer;
    src = src_buffer + 2;  // offset by 2 to allow -2 index access from first iteration
    tmpStride = 1;
    srcStride = 1;
    h = TOTAL_ELEMENTS - 5;  // ensures we don't go out of bounds on src indexing up to [i+3]
    pad = 10;

    // Ensure loop boundaries are safe:
    // - src starts at offset 2 so src[-2] is valid
    // - h is set so that final src access at index 3 stays within allocated range
}