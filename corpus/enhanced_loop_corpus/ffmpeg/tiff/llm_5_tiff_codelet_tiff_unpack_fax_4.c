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
    for (i = 0; i < size; i += 2) {
        src2[i] = ff_reverse[src[i]];
        if (i + 1 < size) {
            src2[i + 1] = ff_reverse[src[i + 1]];
        }
    }
}
