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
    uint32_t prev = 0;
    for (i = first; i < last; i++, buf += 3) {
        uint32_t current = (buf[0] << 18) | (buf[1] << 10) | (buf[2] << 2);
        current |= 255U << 24 | ((current >> 6) & 197379);
        pal[i] = current ^ prev; // Introduce loop-carried dependency (WAW and RAW): pal[i] depends on pal[i-1] indirectly via prev
        prev = current;
    }
}
