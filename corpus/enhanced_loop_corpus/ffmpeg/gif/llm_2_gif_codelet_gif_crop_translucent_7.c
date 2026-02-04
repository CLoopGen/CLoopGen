#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *y_start;
extern int trans;
extern int x_end;
extern int y_end;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *ptr = buf + linesize * (*y_start) + x_end;
    for (int i = *y_start; i < y_end; i++) {
        if (*ptr != trans) {
            is_trans = 0;
            break;
        }
        ptr += linesize; // Stride by linesize to maintain row access
    }
}
