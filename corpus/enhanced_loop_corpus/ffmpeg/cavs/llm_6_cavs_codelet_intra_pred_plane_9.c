#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern int ia;
extern int ih;
extern int iv;
extern  uint8_t *cm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[64];
    for (y = 0; y < 8; y++)
        for (x = 0; x < 8; x++)
            temp[y * 8 + x] = cm[(ia + (x - 3) * ih + (y - 3) * iv + 16) >> 5];
    for (y = 0; y < 8; y++)
        for (x = 0; x < 8; x++)
            d[y * stride + x] = temp[y * 8 + x];
}
