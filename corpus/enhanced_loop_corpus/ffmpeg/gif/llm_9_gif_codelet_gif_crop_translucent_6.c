#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *x_start;
extern int *y_start;
extern int trans;
extern int y_end;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base_offset = linesize * (*y_start) + (*x_start);
    int stride = linesize;
    is_trans = 1;
    // Unroll loop by a factor of 4 to increase computational intensity per iteration
    for (int i = *y_start; i < y_end; i += 4) {
        int match = 1;
        match &= (buf[base_offset] == trans);
        if (i + 1 < y_end) match &= (buf[base_offset + stride] == trans);
        if (i + 2 < y_end) match &= (buf[base_offset + 2 * stride] == trans);
        if (i + 3 < y_end) match &= (buf[base_offset + 3 * stride] == trans);
        if (!match) {
            is_trans = 0;
            break;
        }
        base_offset += 4 * stride;
    }
}
