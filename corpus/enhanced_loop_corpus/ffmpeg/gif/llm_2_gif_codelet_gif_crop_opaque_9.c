#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *y_start;
extern  uint8_t *ref;
extern  int ref_linesize;
extern int x_end;
extern int y_end;
extern int same_column;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *buf_ptr = buf + (*y_start) * linesize + x_end;
    uint8_t *ref_ptr = ref + (*y_start) * ref_linesize + x_end;
    int stride_diff = linesize - ref_linesize; // Adjust for different line strides
    same_column = 1;
    for (int y = *y_start; y <= y_end; y++) {
        if (*ref_ptr != *buf_ptr) {
            same_column = 0;
            break;
        }
        buf_ptr += linesize;
        ref_ptr += ref_linesize;
    }
}
