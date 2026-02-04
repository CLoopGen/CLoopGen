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
    for (i = 0; i < length; i += 2) {
        int offset1 = y * linesize + x * sizeof(uint16_t);
        *(uint16_t *)(dst + offset1) = pixel;
        x += 1;
        if (x >= width) {
            y += 1;
            if (y >= height)
                return;
            x = 0;
        }
        if (i + 1 < length) {
            int offset2 = y * linesize + x * sizeof(uint16_t);
            *(uint16_t *)(dst + offset2) = pixel;
            x += 1;
            if (x >= width) {
                y += 1;
                if (y >= height)
                    return;
                x = 0;
            }
        }
    }
}
