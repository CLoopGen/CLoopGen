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
    // Variant 1: Strided memory access with step size of 2 (reverse traversal with stride)
    int stride = 2;
    for (i = ((1 << bitspersample) - 1) | 1; i >= 0; i -= stride) {
        if (i >= (1 << bitspersample)) continue;
        red[i] = (((red[i]) * 255L) / ((1L << 16) - 1));
        green[i] = (((green[i]) * 255L) / ((1L << 16) - 1));
        blue[i] = (((blue[i]) * 255L) / ((1L << 16) - 1));
        
        int prev = i - 1;
        if (prev >= 0 && prev < (1 << bitspersample)) {
            red[prev] = (((red[prev]) * 255L) / ((1L << 16) - 1));
            green[prev] = (((green[prev]) * 255L) / ((1L << 16) - 1));
            blue[prev] = (((blue[prev]) * 255L) / ((1L << 16) - 1));
        }
    }
}
