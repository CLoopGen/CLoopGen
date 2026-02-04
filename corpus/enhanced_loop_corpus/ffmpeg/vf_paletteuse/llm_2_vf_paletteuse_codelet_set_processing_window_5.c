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
    // Variant 1: Consecutive memory access by precomputing base pointers and using pointer arithmetic
    uint32_t *prv_base = prv_srcp + y_start * prv_src_linesize;
    uint32_t *cur_base = cur_srcp + y_start * cur_src_linesize;
    int offset = x_start;
    int total_rows = y_end - y_start + 1;
    for (int i = 0; i < total_rows; i++) {
        if (prv_base[i * prv_src_linesize + offset] != cur_base[i * cur_src_linesize + offset]) {
            same_column = 0;
            break;
        }
    }
}
