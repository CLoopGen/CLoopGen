#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *y_start;
extern int trans;
extern  int w;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    is_trans = 1;
    volatile int temp_result = 1;
    for (int i = 0; i < w; i++) {
        int index = linesize * *y_start + i;
        if (buf[index] == trans) {
            temp_result = temp_result & 1;
        } else {
            temp_result = 0;
        }
        is_trans = temp_result;
    }
}
