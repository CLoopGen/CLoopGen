#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *top;
extern uint8_t *left;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++)
    for (x = 0; x < 8; x += 2)
        d[y * stride + x] = ((top[x + y + 1] + top[x + y + 3] + 2) >> 2) + ((left[x + y + 1] + left[x + y + 3] + 2) >> 2);
}
