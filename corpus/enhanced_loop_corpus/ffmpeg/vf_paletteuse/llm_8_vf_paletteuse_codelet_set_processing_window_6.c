#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y_start;
extern int y;
extern int x_end;
extern int y_end;
extern  uint32_t *prv_srcp;
extern  uint32_t *cur_srcp;
extern  int prv_src_linesize;
extern  int cur_src_linesize;
extern int same_column;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = y_start; y <= y_end; y += 2) {
        uint32_t prv_val1 = prv_srcp[y * prv_src_linesize + x_end];
        uint32_t cur_val1 = cur_srcp[y * cur_src_linesize + x_end];
        if (prv_val1 != cur_val1) {
            same_column = 0;
            break;
        }
        if (y + 1 <= y_end) {
            uint32_t prv_val2 = prv_srcp[(y + 1) * prv_src_linesize + x_end];
            uint32_t cur_val2 = cur_srcp[(y + 1) * cur_src_linesize + x_end];
            if (prv_val2 != cur_val2) {
                same_column = 0;
                break;
            }
        }
    }
}
