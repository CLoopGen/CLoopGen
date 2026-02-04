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
    int temp_r = 0, temp_g = 0, temp_b = 0;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int offset = x * 4 + y * stride;
            temp_r += block[0 + offset];
            temp_g += block[1 + offset];
            temp_b += block[2 + offset];
        }
    }
    r += temp_r;
    g += temp_g;
    b += temp_b;
}
