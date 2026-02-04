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
    same_column = 1;
    uint32_t diff_accum = 0;
    for (y = y_start; y <= y_end; y++) {
        uint32_t prv_val = prv_srcp[y * prv_src_linesize + x_start];
        uint32_t cur_val = cur_srcp[y * cur_src_linesize + x_start];
        diff_accum |= (prv_val ^ cur_val);
        if (diff_accum != 0) {
            same_column = 0;
        }
    }
    if (diff_accum != 0) {
        same_column = 0;
    } else {
        same_column = 1;
    }
}
