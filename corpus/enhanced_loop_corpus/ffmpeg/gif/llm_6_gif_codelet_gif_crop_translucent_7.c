#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *y_start;
extern int trans;
extern int x_end;
extern int y_end;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_is_trans = 1;
    uint8_t local_trans = trans;
    int local_linesize = linesize;
    int local_x_end = x_end;
    for (int i = *y_start; i < y_end; i++) {
        int index = local_linesize * i + local_x_end;
        if (buf[index] != local_trans) {
            temp_is_trans = 0;
        }
    }
    is_trans = temp_is_trans;
}
