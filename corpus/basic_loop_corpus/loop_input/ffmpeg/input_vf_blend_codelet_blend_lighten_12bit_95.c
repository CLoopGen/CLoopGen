#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

ptrdiff_t top_linesize = 1024;
ptrdiff_t bottom_linesize = 1024;
ptrdiff_t dst_linesize = 1024;
ptrdiff_t width = 512;
ptrdiff_t height = 512;
uint16_t *top;
uint16_t *bottom;
uint16_t *dst;
double opacity = 0.75;
int i;
int j;

void init_vars() {
    size_t total_size = height * 1024 * sizeof(uint16_t);
    
    top = (uint16_t*)aligned_alloc(64, total_size);
    bottom = (uint16_t*)aligned_alloc(64, total_size);
    dst = (uint16_t*)aligned_alloc(64, total_size);
    
    if (!top || !bottom || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (size_t idx = 0; idx < total_size / sizeof(uint16_t); idx++) {
        top[idx] = rand() % 65536;
        bottom[idx] = rand() % 65536;
        dst[idx] = 0;
    }
}