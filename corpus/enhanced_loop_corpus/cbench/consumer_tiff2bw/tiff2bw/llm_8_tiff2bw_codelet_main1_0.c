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
for (i = (1 << bitspersample) - 1; i >= 0; i -= 2) {
    if (i >= 0) {
        red[i] = (((red[i]) * 255L) / ((1L << 16) - 1));
        green[i] = (((green[i]) * 255L) / ((1L << 16) - 1));
        blue[i] = (((blue[i]) * 255L) / ((1L << 16) - 1));
    }
    if (i - 1 >= 0) {
        red[i-1] = (((red[i-1]) * 255L) / ((1L << 16) - 1));
        green[i-1] = (((green[i-1]) * 255L) / ((1L << 16) - 1));
        blue[i-1] = (((blue[i-1]) * 255L) / ((1L << 16) - 1));
    }
}
}
