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
    // Variant 2: Consecutive array-like access via temporary pointer with fixed offset stride simulation
    uint16_t *ptr = pixels + row * linesize + (w - 1) * 4;
    for (j = w - 1; j >= leftEdge && ptr[-(w - 1 - j) * 4] == 0; j--)
        ;
}
