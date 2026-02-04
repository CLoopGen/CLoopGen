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
    for (i = 0; i < length; i++) {
        int offset = y * linesize + x * sizeof(uint16_t);
        *(uint16_t *)(dst + offset) = pixel;
        x += (y < height);
        if (x >= width && y < height) {
            x = 0;
            y += 1;
        } else if (y >= height) {
            return;
        }
    }
}
