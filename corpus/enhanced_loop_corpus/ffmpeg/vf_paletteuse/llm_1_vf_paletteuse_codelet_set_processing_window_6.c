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
    for (int outer = y_start; outer <= y_end; outer += 2) {
        y = outer;
        if (prv_srcp[y * prv_src_linesize + x_end] != cur_srcp[y * cur_src_linesize + x_end]) {
            same_column = 0;
            break;
        }
        if (outer + 1 <= y_end) {
            y = outer + 1;
            if (prv_srcp[y * prv_src_linesize + x_end] != cur_srcp[y * cur_src_linesize + x_end]) {
                same_column = 0;
                break;
            }
        }
    }
}
