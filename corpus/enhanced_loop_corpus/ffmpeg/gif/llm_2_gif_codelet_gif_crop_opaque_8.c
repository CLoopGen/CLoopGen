#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *x_start;
extern int *y_start;
extern  uint8_t *ref;
extern  int ref_linesize;
extern int y_end;
extern int same_column;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing elements sequentially in row-major order, we maintain the same logical check
    // but access memory with a fixed stride by unrolling the loop two iterations at a time.
    int y = *y_start;
    for (; y <= y_end - 1; y += 2) {
        int offset1 = y * linesize + *x_start;
        int offset2 = (y + 1) * linesize + *x_start;
        int ref_offset1 = y * ref_linesize + *x_start;
        int ref_offset2 = (y + 1) * ref_linesize + *x_start;

        if (ref[ref_offset1] != buf[offset1]) {
            same_column = 0;
            break;
        }
        if (ref[ref_offset2] != buf[offset2]) {
            same_column = 0;
            break;
        }
    }
    // Handle remaining element if y_end is odd
    if (y <= y_end) {
        if (ref[y * ref_linesize + *x_start] != buf[y * linesize + *x_start]) {
            same_column = 0;
        }
    }
}
