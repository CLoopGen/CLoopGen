#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_reverse[256];
extern  uint8_t *src;
extern int size;
extern int i;
extern uint8_t *src2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size <= 0) return;
    i = 0;
    for (int block = 0; block < size; block += 1) {
        for (int step = 0; step < 1 && i < size; step++, i++)
            src2[i] = ff_reverse[src[i]];
    }
}
