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
int step = 2;
for (i = first; i < last; i += step, buf += 6) {
    if (i + 1 < last) {
        pal[i] = (buf[0] << 18) | (buf[1] << 10) | (buf[2] << 2);
        pal[i] |= 255U << 24 | (pal[i] >> 6) & 197379;
        pal[i+1] = (buf[3] << 18) | (buf[4] << 10) | (buf[5] << 2);
        pal[i+1] |= 255U << 24 | (pal[i+1] >> 6) & 197379;
    } else {
        pal[i] = (buf[0] << 18) | (buf[1] << 10) | (buf[2] << 2);
        pal[i] |= 255U << 24 | (pal[i] >> 6) & 197379;
    }
}
}
