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
for (i = 0; i < 768; i++) {
    int idx = i / 3;
    int rem = i % 3;
    c[rem] = (*data << 2) | (*data >> 4);
    data++;
    if (rem == 2) {
        palette[idx] = 255U << 24 | ((((const uint8_t *)(c))[0] << 16) | (((const uint8_t *)(c))[1] << 8) | ((const uint8_t *)(c))[2]);
    }
}
}
