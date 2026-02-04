#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint32_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t prev = src[0];
    for (i = 0; i < 4; i++) {
        uint32_t current = src[i];
        src[i] = ((current << 16) | (current >> 16)) ^ src[7 - i] ^ prev;
        prev = current;
    }
}
