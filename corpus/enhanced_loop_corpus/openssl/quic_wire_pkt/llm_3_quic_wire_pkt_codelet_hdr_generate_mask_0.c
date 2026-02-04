#include <stdio.h>

#include <inttypes.h>

extern unsigned char *mask;
extern unsigned char dst[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse order (consecutive but backward) memory access
    for (i = 4; i < 5 && i >= 0; --i) {
        mask[i] = dst[i];
    }
}
