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
    for (; y <= y_end; y++) {
        same_column = 1;
        if (ref[y * ref_linesize + *x_start] != buf[y * linesize + *x_start]) {
            same_column = 0;
            break;
        }
    }
}
