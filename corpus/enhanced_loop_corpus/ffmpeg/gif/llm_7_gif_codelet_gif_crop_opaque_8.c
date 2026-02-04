#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *x_start;
extern int *y_start;
extern  uint8_t *ref;
extern  int ref_linesize;
extern int y_end;
extern int same_column;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_result = 1;
    for (int y = *y_start; y <= y_end; y += 2) {
        int idx1 = y * ref_linesize + *x_start;
        int idx2 = y * linesize + *x_start;
        if (ref[idx1] != buf[idx2]) {
            local_result = 0;
        }
        if (y + 1 <= y_end) {
            int idx3 = (y + 1) * ref_linesize + *x_start;
            int idx4 = (y + 1) * linesize + *x_start;
            if (ref[idx3] != buf[idx4]) {
                local_result = 0;
            }
        }
    }
    if (!local_result) {
        same_column = 0;
    }
}
