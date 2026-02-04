#include <stdio.h>

#include <inttypes.h>

extern unsigned char inbuf[1200];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    size_t size = sizeof(inbuf);
    for (size_t i = size; i > 0; --i) {
        size_t idx = i - 1;
        inbuf[idx] = (unsigned char)(255 & idx);
    }
}
