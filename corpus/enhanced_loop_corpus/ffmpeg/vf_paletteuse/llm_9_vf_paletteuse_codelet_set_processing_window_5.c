#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_start;
extern int y_start;
extern int y;
extern int y_end;
extern  uint32_t *prv_srcp;
extern  uint32_t *cur_srcp;
extern  int prv_src_linesize;
extern  int cur_src_linesize;
extern int same_column;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    int limit = y_end - 3;
    for (y = y_start; y <= limit; y += step) {
        uint32_t val_prev_0 = prv_srcp[y * prv_src_linesize + x_start];
        uint32_t val_curr_0 = cur_srcp[y * cur_src_linesize + x_start];
        uint32_t val_prev_1 = prv_srcp[(y + 1) * prv_src_linesize + x_start];
        uint32_t val_curr_1 = cur_srcp[(y + 1) * cur_src_linesize + x_start];
        uint32_t val_prev_2 = prv_srcp[(y + 2) * prv_src_linesize + x_start];
        uint32_t val_curr_2 = cur_srcp[(y + 2) * cur_src_linesize + x_start];
        uint32_t val_prev_3 = prv_srcp[(y + 3) * prv_src_linesize + x_start];
        uint32_t val_curr_3 = cur_srcp[(y + 3) * cur_src_linesize + x_start];

        if (val_prev_0 != val_curr_0 || 
            val_prev_1 != val_curr_1 || 
            val_prev_2 != val_curr_2 || 
            val_prev_3 != val_curr_3) {
            same_column = 0;
            break;
        }
    }
    // Handle remaining iterations if any
    for (; y <= y_end; y++) {
        if (prv_srcp[y * prv_src_linesize + x_start] != cur_srcp[y * cur_src_linesize + x_start]) {
            same_column = 0;
            break;
        }
    }
}
