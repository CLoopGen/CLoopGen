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
    for (j = 0; j < 3; j++) {
        c[j] = (*(data + i * 3 + j) << 2) | (*(data + i * 3 + j) >> 4);
    }
    palette[i] = 255U << 24 | ((c[0] << 16) | (c[1] << 8) | c[2]);
}
}
