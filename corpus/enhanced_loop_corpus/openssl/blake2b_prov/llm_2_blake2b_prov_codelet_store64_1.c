#include <stdio.h>

#include <inttypes.h>

extern uint64_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse order (stride of 2, wrapping around)
    int stride = 2;
    for (i = 0; i < 8; i++) {
        int index = (i * stride) % 8;
        p[index] = (uint8_t)(w >> (8 * i));
    }
}
