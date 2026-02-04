#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int x;
extern int y;
extern int stride;
extern int blocksize;
extern int highest;
extern int lowest;
extern int i;
extern int j;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_low = lowest;
    int temp_high = highest;
    for (i = 0; i <= blocksize * 2; i++) {
        int row_min = 255;
        int row_max = 0;
        for (j = 0; j <= 15; j++) {
            pos = (y + i) * stride + (x + j);
            uint8_t val = src[pos];
            if (val < row_min) row_min = val;
            if (val > row_max) row_max = val;
        }
        if (row_min < temp_low) temp_low = row_min;
        if (row_max > temp_high) temp_high = row_max;
    }
    lowest = temp_low;
    highest = temp_high;
}
