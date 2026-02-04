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
for (i = 0; i < 512; i++) {
    for (j = 0; j < 3; j++, data++)
        c[j] = (*data << 3) | (*data >> 5) | (*data << 1);
    palette[i/2] = 255U << 24 | ((((const uint8_t *)(c))[0] << 16) | (((const uint8_t *)(c))[1] << 8) | ((const uint8_t *)(c))[2]);
}
}
