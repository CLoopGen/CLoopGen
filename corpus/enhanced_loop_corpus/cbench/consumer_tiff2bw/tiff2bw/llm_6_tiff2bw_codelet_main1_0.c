#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 bitspersample;
extern uint16 *red;
extern uint16 *green;
extern uint16 *blue;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16 temp_red, temp_green, temp_blue;
    for (i = (1 << bitspersample) - 1; i >= 0; i--) {
        temp_red   = (((red[i]) * 255L) / ((1L << 16) - 1));
        temp_green = (((green[i]) * 255L) / ((1L << 16) - 1));
        temp_blue  = (((blue[i]) * 255L) / ((1L << 16) - 1));
        red[i]     = temp_red;
        green[i]   = temp_green;
        blue[i]    = temp_blue;
    }
}
