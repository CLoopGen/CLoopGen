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
    for (i = 0; i <= (ssize_t)65535UL; i += 2) {
        grays[i].red = (~0U);
        grays[i].green = (~0U);
        grays[i].blue = (~0U);
        grays[i].alpha = (~0U);
        grays[i].black = (~0U);
        if (i + 1 <= 65535) {
            grays[i+1].red = (~0U);
            grays[i+1].green = (~0U);
            grays[i+1].blue = (~0U);
            grays[i+1].alpha = (~0U);
            grays[i+1].black = (~0U);
        }
    }
}
