#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
uint8_t *cm;
int i;

#define DATA_SIZE_MB 64
#define BUFFER_SIZE (DATA_SIZE_MB * 1024 * 1024)

static uint8_t internal_dst_buffer[BUFFER_SIZE];
static uint8_t internal_src_buffer[BUFFER_SIZE];
static uint8_t internal_cm_buffer[512];

void init_vars() {
    const int width = 9;  
    const int max_h = (BUFFER_SIZE / width);
    
    h = max_h > 1000 ? 1000 : max_h - 1; 
    if (h <= 0) h = 1;

    srcStride = width;
    dstStride = width;

    cm = internal_cm_buffer + 256; 

    dst = internal_dst_buffer;
    src = internal_src_buffer;

    for (int j = 0; j < 512; j++) {
        internal_cm_buffer[j] = (uint8_t)(j & 0xFF);
    }

    for (int j = 0; j < BUFFER_SIZE; j++) {
        internal_dst_buffer[j] = (uint8_t)(j % 256);
        internal_src_buffer[j] = (uint8_t)((j * 7) % 256);
    }

    i = 0;
}