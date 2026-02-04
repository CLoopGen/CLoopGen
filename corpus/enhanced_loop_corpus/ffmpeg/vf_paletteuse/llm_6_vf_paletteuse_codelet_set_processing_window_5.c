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
    int temp_same_column = 1;
    uint32_t prev_value = 0;
    uint32_t curr_value = 0;
    for (y = y_start; y <= y_end; y++) {
        prev_value = prv_srcp[y * prv_src_linesize + x_start];
        curr_value = cur_srcp[y * cur_src_linesize + x_start];
        if (prev_value != curr_value) {
            temp_same_column = 0;
            break;
        }
    }
    same_column = temp_same_column;
}
