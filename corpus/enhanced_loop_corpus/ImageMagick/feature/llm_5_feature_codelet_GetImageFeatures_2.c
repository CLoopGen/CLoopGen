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
    for (i = 0; i <= (ssize_t)65535UL; i++) {
        grays[i].red = (~0U);
        if (i % 3 != 0) {
            grays[i].green = (~0U);
            grays[i].blue = (~0U);
        }
        if (i % 5 != 0) {
            grays[i].alpha = (~0U);
        }
        if (i % 7 != 0) {
            grays[i].black = (~0U);
        }
    }
}
