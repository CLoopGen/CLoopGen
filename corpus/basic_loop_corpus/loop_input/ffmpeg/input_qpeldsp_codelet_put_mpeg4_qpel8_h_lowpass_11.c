#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
uint8_t *cm;
int i;

static uint8_t internal_dst[TOTAL_ELEMENTS];
static uint8_t internal_src[TOTAL_ELEMENTS];
static uint8_t internal_cm[512];

void init_vars() {
    const int width = 9;  
    const int max_h = (TOTAL_ELEMENTS / width);
    
    h = max_h > 10000 ? 10000 : max_h;
    
    dstStride = width;
    srcStride = width;
    
    dst = internal_dst;
    src = internal_src;
    cm = internal_cm;
    
    for (int idx = 0; idx < TOTAL_ELEMENTS; idx++) {
        internal_src[idx] = (uint8_t)(idx % 256);
        internal_dst[idx] = 0;
    }
    
    for (int idx = 0; idx < 512; idx++) {
        internal_cm[idx] = (uint8_t)((idx * 73) % 256); 
    }
    
    i = 0;
}