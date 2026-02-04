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
    for (ssize_t outer = 0; outer <= 255; outer++) {
        for (ssize_t inner = 0; inner <= 255; inner++) {
            ssize_t i = (outer << 8) | inner;
            grays[i].red = (~0U);
            grays[i].green = (~0U);
            grays[i].blue = (~0U);
            grays[i].alpha = (~0U);
            grays[i].black = (~0U);
        }
    }
}
