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
for (y = 0; y < 8; y++)
    for (x = 0; x < 8; x++)
        d[y * stride + x] = cm[(ia + (x - 3) * ih + (y - 3) * iv + 16) >> 5];

}
