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
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    IDWTELEM **lines = sb->line + block_h * mb_y;
    int height = ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)) - block_h * mb_y;
    for (int i = 0; i < height; i++) {
        IDWTELEM *line = lines[i];
        for (int j = w - 1; j >= 0; j--) {
            line[j] -= 128 << 4;
        }
    }
}
