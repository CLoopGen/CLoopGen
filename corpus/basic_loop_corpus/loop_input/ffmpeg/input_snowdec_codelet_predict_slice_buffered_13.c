#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

typedef struct slice_buffer_s {
    IDWTELEM **line;
    IDWTELEM **data_stack;
    int data_stack_top;
    int line_count;
    int line_width;
    int data_count;
    IDWTELEM *base_buffer;
} slice_buffer;

slice_buffer *sb;
int mb_y;
int x;
int y;
int block_h;
int ref_stride;
uint8_t *dst8;
int w;
int h;

static IDWTELEM** create_line_array(int height, int width) {
    IDWTELEM** lines = (IDWTELEM**)calloc(height, sizeof(IDWTELEM*));
    for (int i = 0; i < height; i++) {
        lines[i] = (IDWTELEM*)malloc(width * sizeof(IDWTELEM));
        for (int j = 0; j < width; j++) {
            lines[i][j] = (rand() % 512) - 256;
        }
    }
    return lines;
}

static uint8_t* create_dst_buffer(int size) {
    uint8_t* buf = (uint8_t*)malloc(size);
    for (int i = 0; i < size; i++) {
        buf[i] = 0;
    }
    return buf;
}

void init_vars() {
    const int total_data_size_mb = 64;
    w = 2048;
    h = (total_data_size_mb * 1024 * 1024) / w;
    if (h < 32) h = 32;
    
    block_h = 16;
    mb_y = 1;
    ref_stride = w;
    
    sb = (slice_buffer*)malloc(sizeof(slice_buffer));
    sb->line_count = h;
    sb->line_width = w;
    sb->data_stack_top = 0;
    sb->data_count = 0;
    sb->data_stack = NULL;
    sb->base_buffer = NULL;
    sb->line = create_line_array(h, w);
    
    dst8 = create_dst_buffer(h * ref_stride);
}