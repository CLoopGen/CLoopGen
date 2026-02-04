#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern int width;
extern uint8_t prev;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Processes every second element in forward order
    for (i = 0; i < width; i += 2) {
        dst[i] = src[i] - prev;
        prev = src[i];
        if (i + 1 < width) {
            dst[i + 1] = src[i + 1] - prev;
            prev = src[i + 1];
        }
    }
}
