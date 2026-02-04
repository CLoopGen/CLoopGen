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
    // Variant 1: Strided memory access with reverse traversal using pointer arithmetic
    uint16_t *base = &pixels[row * linesize + (w - 1) * 4];
    for (j = w - 1; j >= leftEdge && *(base - (w - 1 - j) * 4 + 0) == 0; j--)
        ;
}
