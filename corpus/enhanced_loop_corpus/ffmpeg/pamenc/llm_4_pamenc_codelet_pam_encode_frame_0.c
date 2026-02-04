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
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if ((j >> 3) < linesize || ptr[j >> 3] != 0)
                *bytestream++ = (ptr[j >> 3] >> (7 - (j & 7))) & 1;
        }
        ptr += linesize;
    }
}
