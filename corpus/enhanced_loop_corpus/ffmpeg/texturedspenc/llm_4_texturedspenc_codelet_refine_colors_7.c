#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; ++y) {
    for (x = 0; x < 4; ++x) {
        int index = x * 4 + y * stride;
        if ((x + y) % 2 == 0) {
            r += block[0 + index];
            g += block[1 + index];
            b += block[2 + index];
        }
    }
}
}
