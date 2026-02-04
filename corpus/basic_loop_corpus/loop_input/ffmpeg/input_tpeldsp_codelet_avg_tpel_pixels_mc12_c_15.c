#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define WIDTH 1920
#define HEIGHT 1080
#define STRIDE (WIDTH + 16)

static uint8_t *dst_base;
static uint8_t *src_base;

uint8_t *dst;
uint8_t *src;
int stride = STRIDE;
int width = WIDTH;
int height = HEIGHT;
int i;
int j;

void init_vars() {
    size_t total_size = (size_t)stride * height * sizeof(uint8_t);
    
    src_base = aligned_alloc(32, total_size * 2);
    dst_base = src_base + total_size;
    
    if (!src_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    src = src_base;
    dst = dst_base;
    
    for (size_t idx = 0; idx < total_size; idx++) {
        src_base[idx] = rand() & 0xFF;
        dst_base[idx] = rand() & 0xFF;
    }
}