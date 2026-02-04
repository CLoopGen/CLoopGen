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
    for (j = w - 1; j >= leftEdge; j--) {
        if (pixels[row * linesize + j * 4 + 0] != 0) {
            break;
        }
    }
}
