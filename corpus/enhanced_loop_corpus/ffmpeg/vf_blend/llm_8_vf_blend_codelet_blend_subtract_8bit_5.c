#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    ptrdiff_t offset = i * width;
    for (j = 0; j < width; j += 4) {
        uint8_t* dst_ptr = &dst[j];
        uint8_t* top_ptr = &top[j];
        uint8_t* bottom_ptr = &bottom[j];
        
        dst_ptr[0] = top_ptr[0] + ((((0) > (top_ptr[0] - bottom_ptr[0]) ? (0) : (top_ptr[0] - bottom_ptr[0]))) - top_ptr[0]) * opacity;
        dst_ptr[1] = top_ptr[1] + ((((0) > (top_ptr[1] - bottom_ptr[1]) ? (0) : (top_ptr[1] - bottom_ptr[1]))) - top_ptr[1]) * opacity;
        dst_ptr[2] = top_ptr[2] + ((((0) > (top_ptr[2] - bottom_ptr[2]) ? (0) : (top_ptr[2] - bottom_ptr[2]))) - top_ptr[2]) * opacity;
        dst_ptr[3] = top_ptr[3] + ((((0) > (top_ptr[3] - bottom_ptr[3]) ? (0) : (top_ptr[3] - bottom_ptr[3]))) - top_ptr[3]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
