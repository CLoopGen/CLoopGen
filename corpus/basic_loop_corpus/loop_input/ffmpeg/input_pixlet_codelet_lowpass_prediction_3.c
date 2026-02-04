#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int16_t *pred;
int width;
int height;
ptrdiff_t stride;
int16_t val;
int i;
int j;

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / sizeof(int16_t))
#define TOTAL_ELEMENTS (DATA_SIZE_MB * ELEMENTS_PER_MB)

static int16_t *dst_buffer;
static int16_t *pred_buffer;

void init_vars() {
    width = 1920;
    height = 1080;
    stride = 2048;
    
    size_t total_elements = (size_t)stride * (size_t)height;
    if (total_elements > TOTAL_ELEMENTS) {
        total_elements = TOTAL_ELEMENTS;
        height = TOTAL_ELEMENTS / stride;
    }
    
    dst_buffer = (int16_t*)aligned_alloc(32, total_elements * sizeof(int16_t));
    pred_buffer = (int16_t*)aligned_alloc(32, total_elements * sizeof(int16_t));
    
    if (!dst_buffer || !pred_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (size_t idx = 0; idx < total_elements; idx++) {
        dst_buffer[idx] = rand() % 1000 - 500;
        pred_buffer[idx] = rand() % 1000 - 500;
    }
    
    dst = dst_buffer;
    pred = pred_buffer;
    val = 0;
    i = 0;
    j = 0;
}