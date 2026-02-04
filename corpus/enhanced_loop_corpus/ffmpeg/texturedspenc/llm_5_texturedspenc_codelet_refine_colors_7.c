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
for (y = 0; y < 4; y++) {
    int row_contrib = y * stride;
    for (x = 0; x < 4; x++) {
        int offset = x * 4;
        r += block[0 + offset + row_contrib];
        if (x >= 2) {
            g += block[1 + offset + row_contrib];
        } else {
            b += block[2 + offset + row_contrib];
        }
    }
}
}
