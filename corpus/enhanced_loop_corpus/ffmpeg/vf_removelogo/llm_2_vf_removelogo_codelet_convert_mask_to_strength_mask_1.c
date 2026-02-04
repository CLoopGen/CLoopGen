#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int linesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing row by row, we access memory with a stride (e.g., every second element),
    // then cover the rest in a second phase. Here we do horizontal striding by 2.
    for (int stride = 0; stride < 2; stride++) {
        for (y = 1; y < h - 1; y++)
            for (x = 1 + stride; x < w - 1; x += 2)
                data[(y * linesize) + x] = (((data[(y * linesize) + x]) >> 2) + (data[(y * linesize) + x]));
    }
}
