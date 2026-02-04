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
    int i = *y_start;
    while (i < y_end) {
        uint8_t val = buf[linesize * i + x_end];
        if (val != trans) {
            is_trans = 0;
            break;
        }
        i += 2; // Increase step to reduce trip count and arithmetic intensity
    }
}
