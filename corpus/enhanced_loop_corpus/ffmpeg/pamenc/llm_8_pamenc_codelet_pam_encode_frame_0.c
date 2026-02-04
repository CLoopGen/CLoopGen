#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bytestream;
extern int i;
extern int h;
extern int w;
extern int linesize;
extern uint8_t *ptr;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    for (j = 0; j < w; j++)
        *bytestream++ = (ptr[j >> 3] >> (7 - (j & 7))) & 1;
    ptr += linesize;
    if (i + 1 < h) {
        for (j = 0; j < w; j++)
            *bytestream++ = (ptr[j >> 3] >> (7 - (j & 7))) & 1;
        ptr += linesize;
    }
}
}
