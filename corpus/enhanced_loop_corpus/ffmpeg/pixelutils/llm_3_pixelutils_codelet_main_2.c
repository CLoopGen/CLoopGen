#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf2;
extern uint32_t state;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int width = 640;
    int height = 480;
    for (k = 0; k < width * height; k++) {
        int y = k / width;
        int x = k % width;
        int index = y + x * height; // Transposed access: column-major order
        state = state * 1664525 + 1013904223;
        buf2[index] = state >> 24;
    }
}
