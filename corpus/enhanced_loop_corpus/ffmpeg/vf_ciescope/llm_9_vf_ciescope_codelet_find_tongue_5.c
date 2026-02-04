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
    int step = 2;
    int limit = leftEdge + ((w - leftEdge) % 2);
    for (j = w - 1; j >= limit; j -= step) {
        if (pixels[row * linesize + j * 4 + 0] != 0) break;
        if (j - 1 >= leftEdge && pixels[row * linesize + (j - 1) * 4 + 0] != 0) {
            j--;
            break;
        }
    }
}
