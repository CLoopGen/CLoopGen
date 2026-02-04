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
    same_column = 1;
    for (y = y_start; same_column && y <= y_end; y++) {
        if (prv_srcp[y * prv_src_linesize + x_end] == cur_srcp[y * cur_src_linesize + x_end]) {
            continue;
        } else {
            same_column = 0;
        }
    }
}
