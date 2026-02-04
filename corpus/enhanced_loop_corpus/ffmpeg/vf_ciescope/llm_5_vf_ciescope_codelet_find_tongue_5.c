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
    int found = 0;
    for (j = w - 1; j >= leftEdge && !found; j--) {
        uint16_t val = pixels[row * linesize + j * 4 + 0];
        if (val == 0) {
            continue;
        } else {
            j++;
            found = 1;
        }
    }
}
