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
int i, j, pos;
for (i = 0; i <= blocksize; i++) {
    for (j = 0; j <= 31; j++) {
        pos = (y + i) * stride + (x + j);
        uint8_t val = src[pos];
        if (val < lowest) {
            lowest = val;
        }
        if (val > highest) {
            highest = val;
        }
    }
}
}
