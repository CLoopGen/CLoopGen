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
    int y = *y_start;
    int step = 2; // Process two elements per iteration to reduce trip count
    int limit = (y_end - *y_start + 1) / 2;

    for (int i = 0; i < limit; i++) {
        int current_y = y + i * step;
        if (ref[current_y * ref_linesize + *x_start] != buf[current_y * linesize + *x_start]) {
            same_column = 0;
            break;
        }
        // Check the next element if within bounds
        if (current_y + 1 <= y_end) {
            if (ref[(current_y + 1) * ref_linesize + *x_start] != buf[(current_y + 1) * linesize + *x_start]) {
                same_column = 0;
                break;
            }
        }
    }
}
