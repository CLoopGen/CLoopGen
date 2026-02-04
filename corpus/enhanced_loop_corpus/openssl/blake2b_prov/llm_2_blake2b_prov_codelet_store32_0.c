#include <stdio.h>

#include <inttypes.h>

extern uint32_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element, but still write 4 bytes total)
    // We assume p has sufficient space and we're writing with stride 2 for demonstration
    int stride = 2;
    for (i = 0; i < 8; i += stride)
        p[i] = (uint8_t)(w >> (4 * i));  // Adjust shift to match effective byte extraction
}
