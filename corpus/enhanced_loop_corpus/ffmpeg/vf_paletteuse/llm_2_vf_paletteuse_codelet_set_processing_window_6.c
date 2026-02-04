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
    // Variant 1: Consecutive memory access by precomputing base pointers and stepping through aligned data
    uint32_t *prv_base = &prv_srcp[y_start * prv_src_linesize];
    uint32_t *cur_base = &cur_srcp[y_start * cur_src_linesize];
    int row_offset = x_end;
    int prv_stride = prv_src_linesize - 1;
    int cur_stride = cur_src_linesize - 1;

    for (int i = 0; i <= y_end - y_start; i++) {
        if (prv_base[row_offset] != cur_base[row_offset]) {
            same_column = 0;
            break;
        }
        prv_base += prv_stride + 1;
        cur_base += cur_stride + 1;
    }
}
