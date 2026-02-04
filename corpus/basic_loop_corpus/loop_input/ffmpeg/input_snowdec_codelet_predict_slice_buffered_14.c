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
int w;
int h;

static IDWTELEM** allocated_lines;
static IDWTELEM*  buffer_pool;
static int total_lines;
static int lines_allocated;

void init_vars() {
    block_h = 16;
    mb_y = 0;
    w = 1920;
    h = 1088;
    
    total_lines = h;
    lines_allocated = total_lines;
    
    sb = (slice_buffer*)calloc(1, sizeof(slice_buffer));
    allocated_lines = (IDWTELEM**)calloc(lines_allocated, sizeof(IDWTELEM*));
    buffer_pool = (IDWTELEM*)calloc(w * lines_allocated, sizeof(IDWTELEM));
    
    for (int i = 0; i < lines_allocated; i++) {
        allocated_lines[i] = buffer_pool + i * w;
        for (int j = 0; j < w; j++) {
            allocated_lines[i][j] = 128 << 4;
        }
    }
    
    sb->line = allocated_lines;
    sb->data_stack = NULL;
    sb->data_stack_top = 0;
    sb->line_count = lines_allocated;
    sb->line_width = w;
    sb->data_count = 0;
    sb->base_buffer = buffer_pool;
}