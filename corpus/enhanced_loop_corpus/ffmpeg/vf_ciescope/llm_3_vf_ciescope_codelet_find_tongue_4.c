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
    // Variant 2: Consecutive access using pointer arithmetic with precomputed base
    uint16_t *base = &pixels[row * linesize];
    for (i = 0; i < w && *(base + i * 4) == 0; i++)
        ;
}
