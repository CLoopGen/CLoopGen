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
    for (i = 0; i <= blocksize * 2; i++) {
        for (j = 0; j <= 15; j++) {
            int row = y + i;
            int col = x + j;
            pos = row * stride + col;
            uint8_t val = src[pos];
            if (val < lowest)
                lowest = val;
            else if (val > highest)
                highest = val;
        }
    }
}
