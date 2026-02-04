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
    int stride = linesize;
    int x = *x_start;
    int y_limit = y_end - (*y_start) > 100 ? *y_start + 100 : y_end; // Cap the trip count for reduced computational intensity
    for (int i = *y_start; i < y_limit; i++) {
        if (buf[stride * i + x] != trans) {
            is_trans = 0;
            break;
        }
    }
}
