#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int i;
extern int first;
extern int last;
extern uint32_t *pal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = first; j < last; j++) {
        i = j;
        for (int k = 0; k < 1; k++) {
            pal[i] = (buf[0] << 18) | (buf[1] << 10) | (buf[2] << 2);
            pal[i] |= 255U << 24 | (pal[i] >> 6) & 197379;
            buf += 3;
        }
    }
}
