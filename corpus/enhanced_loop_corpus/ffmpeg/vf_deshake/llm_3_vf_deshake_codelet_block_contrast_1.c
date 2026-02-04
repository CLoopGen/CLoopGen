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
    // Variant 2: Strided Memory Access with Column-Major Traversal
    uint8_t *base = src + y * stride + x;
    for (j = 0; j <= 15; j++) {
        for (i = 0; i <= blocksize * 2; i++) {
            pos = i * stride + j;
            uint8_t val = base[pos];
            if (val < lowest)
                lowest = val;
            else if (val > highest)
                highest = val;
        }
    }
}
