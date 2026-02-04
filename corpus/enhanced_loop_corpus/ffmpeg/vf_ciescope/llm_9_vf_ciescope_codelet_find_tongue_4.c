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
    int limit = w * 2;
    for (i = 0; i < limit && (pixels[(row * linesize + i * 4) % (linesize * 16)] == 0); i++)
        ;
}
