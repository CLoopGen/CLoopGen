#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *left;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++)
    for (x = 0; x < 4; x++) {
        int sum = 0;
        sum += left[y + 0];
        sum += left[y + 1];
        sum += left[y + 1];
        sum += left[y + 2];
        d[(2*y) * stride + (2*x)]     = (sum + 2) >> 2;
        d[(2*y) * stride + (2*x)+1]   = (sum + 3) >> 2;
        d[(2*y+1) * stride + (2*x)]   = (sum + 1) >> 2;
        d[(2*y+1) * stride + (2*x)+1] = (sum + 4) >> 2;
    }
}
