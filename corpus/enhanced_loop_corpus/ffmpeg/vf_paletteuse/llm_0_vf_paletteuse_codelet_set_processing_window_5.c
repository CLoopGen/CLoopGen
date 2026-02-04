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
    for (y = y_start; y <= y_end; y++) {
        for (int x = x_start; x <= x_start; x++) { // Artificially nested loop with fixed range
            if (prv_srcp[y * prv_src_linesize + x] != cur_srcp[y * cur_src_linesize + x]) {
                same_column = 0;
                goto exit_loop;
            }
        }
    }
exit_loop:;
}
