#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern int height;
extern int linesize;
extern int x;
extern int y;
extern int i;
extern int length;
extern uint32_t pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = y * linesize + x * sizeof(uint16_t);
    for (i = 0; i < length; i++) {
        *(uint16_t *)(dst + idx) = pixel;
        idx += sizeof(uint16_t);
        x += 1;
        if (x >= width) {
            y += 1;
            if (y >= height)
                return;
            x = 0;
            idx = y * linesize;
        }
    }
}
