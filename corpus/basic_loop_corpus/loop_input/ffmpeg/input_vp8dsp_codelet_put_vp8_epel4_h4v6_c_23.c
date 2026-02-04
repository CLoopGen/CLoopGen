#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TOTAL_PIXELS (DATA_SIZE_MB * 1024 * 1024)

uint8_t *dst;
ptrdiff_t dststride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

static uint8_t internal_dst[TOTAL_PIXELS];
static uint8_t internal_tmp[TOTAL_PIXELS + 32]; // Extra padding for safe indexing
static uint8_t internal_filter[6] = {8, 12, 16, 12, 8, 4};
static uint8_t internal_cm[512]; // Centered around 256 to handle negative offsets

void init_vars() {
    int width = 4;
    h = TOTAL_PIXELS / width;
    
    dststride = width;
    
    dst = internal_dst;
    tmp = internal_tmp + 8; // Shift base to allow negative indexing: x-2*4 -> x-8
    filter = internal_filter;
    cm = internal_cm + 256; // Allow negative input indices via offset
    
    for (int i = 0; i < 512; i++) {
        internal_cm[i] = (uint8_t)((i - 256) > 0 ? ((i - 256) < 255 ? (i - 256) : 255) : 0);
    }
    
    for (int i = 0; i < TOTAL_PIXELS + 32; i++) {
        internal_tmp[i] = rand() & 0xFF;
    }
    
    for (int i = 0; i < TOTAL_PIXELS; i++) {
        internal_dst[i] = 0;
    }
}