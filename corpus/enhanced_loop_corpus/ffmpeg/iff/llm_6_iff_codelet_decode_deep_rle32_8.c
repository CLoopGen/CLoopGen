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
extern int size;
extern uint32_t pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = y * linesize + x * 4;
    for (i = 0; i < size; i++) {
        *(uint32_t *)(dst + idx) = pixel;
        idx += 4;
        if ((x + 1) >= width) {
            x = 0;
            y += 1;
            idx = y * linesize;
            if (y >= height)
                return;
        } else {
            x += 1;
        }
    }
}
