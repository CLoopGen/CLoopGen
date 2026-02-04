#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t * pixels;
extern  int w;
extern  int linesize;
extern  int row;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t prev_val = 0;
    for (i = 0; i < w; i++) {
        uint16_t current_val = pixels[row * linesize + i * 4 + 0];
        if (current_val != 0 || prev_val != 0) {
            break;
        }
        prev_val = current_val;
    }
}
