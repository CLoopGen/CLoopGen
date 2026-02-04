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
for (i = first; i < last; i++, buf += 3) {
    uint32_t val = (buf[0] << 18) | (buf[1] << 10) | (buf[2] << 2);
    val |= (255U << 24) | ((val >> 6) & 197379);
    pal[i] = val;
}
}
