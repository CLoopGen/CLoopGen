#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_w;
extern int b_h;
extern int x;
extern int y;
extern  unsigned int color;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_color = (uint8_t)color;
    for (y = 0; y < b_h; y++) {
        uint8_t *row = &dst[y * stride];
        for (x = 0; x < b_w; x++) {
            row[x] = local_color;
        }
    }
}
