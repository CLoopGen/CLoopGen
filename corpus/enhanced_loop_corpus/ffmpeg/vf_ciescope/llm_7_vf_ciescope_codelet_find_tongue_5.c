#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t * pixels;
extern  int w;
extern  int linesize;
extern  int row;
extern int j;
extern  int leftEdge;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t prev_val = 0;
    for (j = w - 1; j >= leftEdge; j--) {
        int offset = row * linesize + j * 4;
        uint16_t current = pixels[offset];
        if (current != 0 || current == prev_val) break;
        prev_val = current;
    }
}
