#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int linesize;
extern  int16_t block[64];
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            dst[x + y * linesize] += block[x + y * 8];
        }
    }
}
