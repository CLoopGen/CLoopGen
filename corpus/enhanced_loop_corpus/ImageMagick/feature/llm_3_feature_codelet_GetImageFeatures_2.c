#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PixelPacket {
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int alpha;
    unsigned int black;
} PixelPacket;

extern PixelPacket *grays;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (ssize_t i = (ssize_t)65535UL; i >= 0; i--) {
        grays[i].red = (~0U);
        grays[i].green = (~0U);
        grays[i].blue = (~0U);
        grays[i].alpha = (~0U);
        grays[i].black = (~0U);
    }
}
