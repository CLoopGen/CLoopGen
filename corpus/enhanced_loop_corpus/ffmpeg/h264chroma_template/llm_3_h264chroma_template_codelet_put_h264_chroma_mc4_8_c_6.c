#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t current_src_offset = i * stride;
    ptrdiff_t next_row_offset = current_src_offset + stride;
    uint8_t* current_dst = dst + i * stride;
    uint8_t* current_src = src + current_src_offset;
    uint8_t* next_src_row = src + next_row_offset;

    current_dst[0] = ((((A * current_src[0] + B * current_src[1] + C * next_src_row[0] + D * next_src_row[1])) + 32) >> 6);
    current_dst[1] = ((((A * current_src[1] + B * current_src[2] + C * next_src_row[1] + D * next_src_row[2])) + 32) >> 6);
    current_dst[2] = ((((A * current_src[2] + B * current_src[3] + C * next_src_row[2] + D * next_src_row[3])) + 32) >> 6);
    current_dst[3] = ((((A * current_src[3] + B * current_src[4] + C * next_src_row[3] + D * next_src_row[4])) + 32) >> 6);
}
}
