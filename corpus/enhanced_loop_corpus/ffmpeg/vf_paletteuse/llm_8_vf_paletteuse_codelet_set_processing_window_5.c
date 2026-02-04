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
    for (y = y_start; y <= y_end; y += 2) {
        int idx1 = y * prv_src_linesize + x_start;
        int idx2 = y * cur_src_linesize + x_start;
        if (prv_srcp[idx1] != cur_srcp[idx2]) {
            same_column = 0;
            break;
        }
        if (y + 1 <= y_end) {
            int idx3 = (y + 1) * prv_src_linesize + x_start;
            int idx4 = (y + 1) * cur_src_linesize + x_start;
            if (prv_srcp[idx3] != cur_srcp[idx4]) {
                same_column = 0;
                break;
            }
        }
    }
}
