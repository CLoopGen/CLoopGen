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
    for (i = 0; i <= (ssize_t)32767UL; i++) {
        grays[2*i].red = (~0U) ^ 0U;
        grays[2*i].green = (~0U) ^ 0U;
        grays[2*i].blue = (~0U) ^ 0U;
        grays[2*i].alpha = (~0U) ^ 0U;
        grays[2*i].black = (~0U) ^ 0U;
        grays[2*i+1].red = (~0U) ^ 0U;
        grays[2*i+1].green = (~0U) ^ 0U;
        grays[2*i+1].blue = (~0U) ^ 0U;
        grays[2*i+1].alpha = (~0U) ^ 0U;
        grays[2*i+1].black = (~0U) ^ 0U;
    }
}
