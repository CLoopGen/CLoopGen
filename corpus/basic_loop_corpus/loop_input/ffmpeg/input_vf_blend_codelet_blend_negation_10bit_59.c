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

void init_vars() {
    // Set dimensions to achieve approximately DATA_SIZE_MB of processing
    height = (DATA_SIZE_MB * 1024 * 1024) / (3 * sizeof(uint16_t) * 1024);
    if (height < 1) height = 1;
    width = 1024;

    // Ensure total data size is about DATA_SIZE_MB
    ptrdiff_t total_elements = height * width;
    while (total_elements * 3 * sizeof(uint16_t) > DATA_SIZE_MB * 1024 * 1024) {
        height--;
        total_elements = height * width;
    }
    if (height == 0) {
        height = 1;
        width = (DATA_SIZE_MB * 1024 * 1024) / (3 * sizeof(uint16_t));
    }

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    opacity = 0.75;

    // Allocate aligned memory to prevent issues and improve performance
    posix_memalign((void**)&top, 64, height * top_linesize * sizeof(uint16_t));
    posix_memalign((void**)&bottom, 64, height * bottom_linesize * sizeof(uint16_t));
    posix_memalign((void**)&dst, 64, height * dst_linesize * sizeof(uint16_t));

    // Initialize arrays with sample data in valid range [0, 1023]
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            top[i * top_linesize + j] = rand() % 1024;
            bottom[i * bottom_linesize + j] = rand() % 1024;
            dst[i * dst_linesize + j] = 0;
        }
    }
}