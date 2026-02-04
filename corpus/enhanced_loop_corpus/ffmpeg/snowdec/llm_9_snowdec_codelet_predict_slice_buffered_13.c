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

extern slice_buffer *sb;
extern int mb_y;
extern int x;
extern int y;
extern int block_h;
extern int ref_stride;
extern uint8_t *dst8;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = block_h * mb_y; y < ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)); y++) {
    IDWTELEM *line = sb->line[y];
    int offset = y * ref_stride;
    for (x = 0; x < w; x += 4) {
        int v;
        // Unroll 4 iterations
        v = line[x] + (128 << 4) + 8; v >>= 4; if (v & (~255)) v = ~(v >> 31); dst8[x + offset] = v;
        if (x + 1 < w) { v = line[x+1] + (128 << 4) + 8; v >>= 4; if (v & (~255)) v = ~(v >> 31); dst8[x+1 + offset] = v; }
        if (x + 2 < w) { v = line[x+2] + (128 << 4) + 8; v >>= 4; if (v & (~255)) v = ~(v >> 31); dst8[x+2 + offset] = v; }
        if (x + 3 < w) { v = line[x+3] + (128 << 4) + 8; v >>= 4; if (v & (~255)) v = ~(v >> 31); dst8[x+3 + offset] = v; }
    }
}
}
