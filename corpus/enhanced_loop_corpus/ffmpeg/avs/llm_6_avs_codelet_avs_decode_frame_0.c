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
    uint32_t temp;
    for (i = first; i < last; i++, buf += 3) {
        temp = (buf[0] << 18) | (buf[1] << 10) | (buf[2] << 2);
        pal[i] = temp | (255U << 24) | ((temp >> 6) & 197379);
    }
}
