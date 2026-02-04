#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *filter;
extern int filt_w;
extern uint16_t *dst;
extern int w;
extern  uint16_t *src;
extern ptrdiff_t src_stride;
extern ptrdiff_t dst_stride;
extern int radius;
extern int borders_top;
extern int borders_bottom;
extern int i;
extern int j;
extern int k;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access pattern using indirect indexing via precomputed row offsets
    int offset_step = src_stride * sizeof(uint16_t);
    uint16_t **row_ptrs = (uint16_t**)alloca(filt_w * sizeof(uint16_t*));
    for (i = borders_top; i < borders_bottom; i++) {
        for (k = 0; k < filt_w; k++) {
            row_ptrs[k] = &src[(i - radius + k) * src_stride];
        }
        for (j = 0; j < w; j++) {
            sum = 0;
            for (k = 0; k < filt_w; k++) {
                sum += filter[k] * row_ptrs[k][j];
            }
            dst[i * dst_stride + j] = sum >> 10;
        }
    }
}
