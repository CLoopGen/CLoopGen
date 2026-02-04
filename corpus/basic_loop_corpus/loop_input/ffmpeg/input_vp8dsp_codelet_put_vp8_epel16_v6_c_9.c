#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
ptrdiff_t dststride;
uint8_t *src;
ptrdiff_t srcstride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;

#define FILTER_SIZE 6
#define CM_SIZE 256
#define WIDTH 16
#define HEIGHT (1 << 14)  // 16384 rows

static uint8_t internal_dst[HEIGHT * 32];   // extra padding to prevent overflow
static uint8_t internal_src[HEIGHT * 32];
static uint8_t internal_filter[FILTER_SIZE] = {8, 16, 32, 16, 8, 4};
static uint8_t internal_cm[CM_SIZE];

void init_vars() {
    h = HEIGHT;
    
    dststride = 32;
    srcstride = 32;
    
    dst = internal_dst;
    src = internal_src;
    filter = internal_filter;
    cm = internal_cm;
    
    for (int i = 0; i < CM_SIZE; i++) {
        cm[i] = (uint8_t)(i & 0xFF);
    }
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < 32; j++) {
            src[i * srcstride + j] = rand() & 0xFF;
        }
    }
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < 32; j++) {
            dst[i * dststride + j] = 0;
        }
    }
}