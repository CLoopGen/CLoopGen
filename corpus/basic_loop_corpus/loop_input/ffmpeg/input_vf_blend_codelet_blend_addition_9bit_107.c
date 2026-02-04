#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

ptrdiff_t top_linesize;
ptrdiff_t bottom_linesize;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
uint16_t *top;
uint16_t *bottom;
uint16_t *dst;
double opacity;
int i;
int j;

#define DATA_SIZE_MB 64

static uint16_t *alloc_aligned_size(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size) != 0) {
        return NULL;
    }
    return (uint16_t *)ptr;
}

void init_vars() {
    height = 2048;
    width = 8192 / sizeof(uint16_t); 

    ptrdiff_t row_size_bytes = width * sizeof(uint16_t);

    top_linesize = row_size_bytes / sizeof(uint16_t);
    bottom_linesize = row_size_bytes / sizeof(uint16_t);
    dst_linesize = row_size_bytes / sizeof(uint16_t);

    size_t total_bytes = height * row_size_bytes;
    size_t expected_bytes = DATA_SIZE_MB * 1024 * 1024;
    if (total_bytes < expected_bytes) {
        double scale = sqrt((double)expected_bytes / total_bytes);
        height = (ptrdiff_t)(height * scale);
        width = row_size_bytes / sizeof(uint16_t);
    }

    total_bytes = height * row_size_bytes;
    top = alloc_aligned_size(total_bytes);
    bottom = alloc_aligned_size(total_bytes);
    dst = alloc_aligned_size(total_bytes);

    if (!top || !bottom || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < height * width; idx++) {
        top[idx] = rand() % 512;
        bottom[idx] = rand() % 512;
    }

    opacity = 0.75;
}