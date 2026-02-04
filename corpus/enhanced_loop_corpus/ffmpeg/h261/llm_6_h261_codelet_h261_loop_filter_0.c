#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int x;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (x = 0; x < 8; x++) {
        i = x;
        temp[i] = 4 * src[i];
        temp[i + 7 * 8] = 4 * src[i + 7 * stride];
        temp[i + 16] = temp[i] + temp[i + 7 * 8]; // Introduce RAW dependency: uses previous two writes
    }
}
