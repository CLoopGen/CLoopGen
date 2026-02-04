#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *y_start;
extern  uint8_t *ref;
extern  int ref_linesize;
extern int x_end;
extern int y_end;
extern int same_column;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y = *y_start;
    for (; y <= y_end; y++) {
        uint8_t ref_val = ref[y * ref_linesize + x_end];
        uint8_t buf_val = buf[y * linesize + x_end];
        if (ref_val == buf_val) continue;
        same_column = 0;
        break;
    }
}
