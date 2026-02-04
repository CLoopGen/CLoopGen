#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *data;
extern int i;
extern int j;
extern unsigned char c[3];
extern uint32_t *palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; i++) {
    j = 0;
    c[0] = c[1] = c[2] = 0;
    for (; j < 3; data++, j++) {
        unsigned char val = *data;
        c[j] = (val << 2) | (val >> 4);
        if (c[j] == 0) continue;
    }
    palette[i] = (255U << 24) | ((uint32_t)c[0] << 16) | ((uint32_t)c[1] << 8) | c[2];
}
}
