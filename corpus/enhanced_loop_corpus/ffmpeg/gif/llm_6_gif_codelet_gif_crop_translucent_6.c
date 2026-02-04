#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *x_start;
extern int *y_start;
extern int trans;
extern int y_end;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_is_trans = 1;
    uint8_t local_trans = trans;
    int x_start_val = *x_start;
    for (int i = *y_start; i < y_end; i++) {
        int index = linesize * i + x_start_val;
        if (buf[index] != local_trans) {
            temp_is_trans = 0;
        }
        is_trans = temp_is_trans; // WAW dependency: write to is_trans after each iteration
    }
}
