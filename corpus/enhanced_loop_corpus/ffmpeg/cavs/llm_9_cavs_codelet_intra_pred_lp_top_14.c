#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *top;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y++)
    for (x = 0; x < 4; x++)
        d[y * stride + x] = ((3 * top[x] + 4 * top[x + 1] + top[x + 2] + 4) >> 3);
}
