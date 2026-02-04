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
    int mismatch_found = 0;
    for (y = y_start; y <= y_end && !mismatch_found; y++) {
        uint32_t offset = y * prv_src_linesize + x_end;
        uint32_t offset_cur = y * cur_src_linesize + x_end;
        uint32_t diff = prv_srcp[offset] ^ cur_srcp[offset_cur];
        diff = (diff >> 16) | (diff & 0xFFFF);
        diff = (diff >> 8) | (diff & 0xFF);
        diff = (diff >> 4) | (diff & 0xF);
        diff = (diff >> 2) | (diff & 0x3);
        diff = (diff >> 1) | (diff & 0x1);
        mismatch_found = diff;
    }
    if (mismatch_found) {
        same_column = 0;
    }
}
