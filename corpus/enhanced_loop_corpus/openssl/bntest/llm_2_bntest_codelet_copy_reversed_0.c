#include <stdio.h>

#include <inttypes.h>

extern uint8_t *dst;
extern uint8_t *src;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward memory access with reversed copy using index-based addressing
    for (size_t i = 0; i < len; ++i) {
        dst[i] = src[len - 1 - i];
    }
}
