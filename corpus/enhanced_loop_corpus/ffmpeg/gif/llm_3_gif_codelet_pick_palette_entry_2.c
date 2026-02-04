#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int linesize;
extern int w;
extern int h;
extern int histogram[256];
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using a flat index and pointer arithmetic for coalesced reads
    uint8_t *ptr = buf;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            histogram[*(ptr + x)]++;
        }
        ptr += linesize;
    }
}
