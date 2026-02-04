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
    int temp_lowest = lowest;
    int temp_highest = highest;
    for (i = 0; i <= blocksize * 2; i++) {
        for (j = 0; j <= 15; j++) {
            pos = (y + i) * stride + (x + j);
            uint8_t val = src[pos];
            if (val < temp_lowest)
                temp_lowest = val;
            else if (val > temp_highest) {
                temp_highest = val;
            }
        }
    }
    lowest = temp_lowest;
    highest = temp_highest;
}
