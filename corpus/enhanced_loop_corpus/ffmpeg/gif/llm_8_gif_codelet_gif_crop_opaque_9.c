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
    for (; y <= y_end; y += 2) {
        if (y + 1 <= y_end) {
            uint8_t ref_val1 = ref[y * ref_linesize + x_end];
            uint8_t buf_val1 = buf[y * linesize + x_end];
            uint8_t ref_val2 = ref[(y + 1) * ref_linesize + x_end];
            uint8_t buf_val2 = buf[(y + 1) * linesize + x_end];
            if (ref_val1 != buf_val1 || ref_val2 != buf_val2) {
                same_column = 0;
                break;
            }
        } else {
            if (ref[y * ref_linesize + x_end] != buf[y * linesize + x_end]) {
                same_column = 0;
                break;
            }
        }
    }
}
