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
        grays[i].green = grays[i].red;
        grays[i].blue = grays[i].green;
        grays[i].alpha = grays[i].blue;
        grays[i].black = grays[i].alpha;
    }
}
