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
    for (i = 0; i < size; i++) {
        int index = y * linesize + x * 4;
        *(uint32_t *)(dst + index) = pixel;
        x += 1;
        y += (x >= width);
        x &= (x < width) ? -1 : 0; // Reset x to 0 when it reaches width using bitwise operation
        if (y >= height)
            return;
    }
}
