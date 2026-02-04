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
    int j;
    for (j = 0; j < size; j += 8) {
        for (i = j; i < j + 8 && i < size; i++)
            src2[i] = ff_reverse[src[i]];
    }
}
