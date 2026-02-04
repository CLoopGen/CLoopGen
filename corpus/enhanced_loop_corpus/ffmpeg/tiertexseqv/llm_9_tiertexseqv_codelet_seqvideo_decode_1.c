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
for (i = 0; i < 128; i++) {
    c[0] = (data[0] << 2) | (data[0] >> 4);
    c[1] = (data[1] << 2) | (data[1] >> 4);
    c[2] = (data[2] << 2) | (data[2] >> 4);
    data += 3;
    palette[i] = 255U << 24 | (c[0] << 16) | (c[1] << 8) | c[2];
}
}
