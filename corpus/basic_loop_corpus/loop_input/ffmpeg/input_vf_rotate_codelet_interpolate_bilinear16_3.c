#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

uint8_t *dst_color;
uint8_t *src;
int src_linesize;
int src_linestep;
int int_x;
int int_y;
int frac_x;
int frac_y;
int i;
int int_x1;
int int_y1;

#define DATA_SIZE (128 * 1024 * 1024)

static uint8_t internal_src[DATA_SIZE];
static uint8_t internal_dst_color[256];

void init_vars() {
    const int pixel_size = 2; 
    const int width = 4096;  
    const int height = (DATA_SIZE / pixel_size) / width;
    
    src_linesize = width * pixel_size;
    src_linestep = 2; 
    
    int_x = 100;
    int_y = 50;
    frac_x = 32768; 
    frac_y = 16384; 

    int_x1 = int_x + 1;
    int_y1 = int_y + 1;

    if (int_x1 * pixel_size >= src_linesize) {
        int_x1 = int_x;
    }
    if (int_y1 >= height) {
        int_y1 = int_y;
    }

    src = internal_src;
    dst_color = internal_dst_color;

    for (size_t i = 0; i < DATA_SIZE; ++i) {
        internal_src[i] = (uint8_t)(i & 0xFF);
    }
    memset(internal_dst_color, 0, sizeof(internal_dst_color));
}