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
    int idx = row * linesize + j * 4;
    for (j = w - 1; j >= leftEdge; j--) {
        idx = row * linesize + j * 4;
        if (pixels[idx + 0] != 0) break;
    }
}
