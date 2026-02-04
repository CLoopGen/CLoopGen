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
    int outer_i;
    int unroll_factor = 2;
    int limit = (1 << bitspersample) - 1;
    for (outer_i = limit; outer_i >= 0; outer_i -= unroll_factor) {
        if (outer_i >= 1) {
            // Unroll two iterations: i and i-1
            red[outer_i] = (((red[outer_i]) * 255L) / ((1L << 16) - 1));
            green[outer_i] = (((green[outer_i]) * 255L) / ((1L << 16) - 1));
            blue[outer_i] = (((blue[outer_i]) * 255L) / ((1L << 16) - 1));

            red[outer_i - 1] = (((red[outer_i - 1]) * 255L) / ((1L << 16) - 1));
            green[outer_i - 1] = (((green[outer_i - 1]) * 255L) / ((1L << 16) - 1));
            blue[outer_i - 1] = (((blue[outer_i - 1]) * 255L) / ((1L << 16) - 1));
        } else {
            // Handle leftover element
            red[outer_i] = (((red[outer_i]) * 255L) / ((1L << 16) - 1));
            green[outer_i] = (((green[outer_i]) * 255L) / ((1L << 16) - 1));
            blue[outer_i] = (((blue[outer_i]) * 255L) / ((1L << 16) - 1));
        }
    }
}
